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
		int waitTime = 0, mode = 0, baseLine = 0, frameElapsed = 0;
		char key = 0;
		cv::Size textSize;

		Setting& settings = Setting :: getInstance();

		//Initial mode
		if(settings.inputType == util::IMAGE_LIST)
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
			this->frameView = settings.nextImage();
			//If calibration starts
			if(mode == util::CAPTURING)
			{
				this->controlView->callCalibration(&mode, &(this->frameView), &(this->message), &frameElapsed);
			}

			//Output text
			if(mode == util::CAPTURING)
			{
				this->message = "100/100";
			}
			else if(mode == util::CALIBRATED)
			{
				this->message = "Calibrated";
			}
			else
			{
				this->message = "Press 'g' to start";
			}

			baseLine = 0;
			textSize = cv::getTextSize(this->message, 1, 1, 1, &baseLine);
			cv::Point textOrigin(this->frameView.cols - 2 * textSize.width - 10, this->frameView.rows - 2 * baseLine - 10);

			if(mode == util::CAPTURING)
			{
				if(settings.showUndistorsed)
				{
					this->message = cv::format( "%d/%d Undist", frameElapsed, settings.numFrameForCalibration);
				}
				else
				{
					this->message = cv::format( "%d/%d", frameElapsed, settings.numFrameForCalibration);
				}
			}

			cv::putText(this->frameView, this->message, textOrigin, 1, 1, mode == util::CALIBRATED ?  GREEN : RED);

			cv::imshow(nameWindow, this->frameView);
			waitTime = settings.inputCapture.isOpened() ? 50 : settings.delayForVideoInput;

			key = (char)cv::waitKey(waitTime);

			if(key == util::ESC_KEY)
			{
				break;
			}

			if(key == 'u' && mode == util::CALIBRATED)
			{
				//Disparar a ação de distorcer
				settings.showUndistorsed = !settings.showUndistorsed;
			}

			if(settings.inputCapture.isOpened() && key == 'g')
			{
				mode = util::CAPTURING;
				this->controlView->callResetPoint();
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
