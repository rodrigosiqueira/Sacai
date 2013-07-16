/**
 * @file CameraView.cpp
 **/
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <dataType.hpp>
#include <CameraView.hpp>
#include <Setting.hpp>
#include <ControllerInterface.hpp>
#include <ModelInterface.hpp>

using namespace std;

//namespace view
//{
	CameraView :: CameraView(ControllerInterface * _control, ModelInterface * _model)
	{
		this->modelView = _model;
		this->controlView = _control;
		this->modelView->registerObserver(this);
		nameWindow = "SACAI";
	}

	CameraView :: ~CameraView()
	{
	}

	bool CameraView :: display()
	{
		cv::Scalar GREEN(0, 255, 0), RED(0, 0, 255);
		int waitTime = 0, mode = 0, baseLine = 0;
		char key = 0;

		Setting& setting = Setting :: getInstance();

		//Initial mode
		if(setting.inputType == util::IMAGE_LIST)
		{
			mode = util::CAPTURING;
		}
		else
		{
			mode = util::DETECTION;
		}

		//Main loop
		for(;;)
		{
			this->frameView = setting.nextImage();
			//If calibration starts  !this->controlView->calibDone()
			if(this->operation)
			{
				//callCalibration(int _mode, cv::Mat * _view, std::string * _message) <- Lembrar param
				this->controlView->callCalibration(mode, &(this->frameView), &(this->message));
			}

			cv::Point textOrigin(this->frameView.cols - 2 * textSize.width - 10, this->frameView.rows - 2 * baseLine - 10);

			cv::putText(this->frameView, this->message, textOrigin, 1, 1, mode == util::CALIBRATED ?  GREEN : RED);
			cv::imshow(nameWindow, this->frameView);
			waitTime = setting.inputCapture.isOpened() ? 50 : setting.delayForVideoInput;

			key = (char)cv::waitKey(waitTime);

			if(key == util::ESC_KEY)
			{
				break;
			}

			if(key == 'u' && mode == util::CALIBRATED)
			{
				//Disparar a ação de distorcer
				setting.showUndistorsed = !setting.showUndistorsed;
			}

			if(setting.inputCapture.isOpened() && key == 'g')
			{
				//Disparar a ação de calibrar
				this->operation = true;
				mode = util::CAPTURING;
				//calibration->resetPoint();
			}
		}

		return true;
	}

	void CameraView :: update(int _mode, cv::Mat * _view, std::string * _message)
	{
		//this->message = _message;
		//this->frameView = _frame;
		//this->textSize = _textSize;
	}
//}
