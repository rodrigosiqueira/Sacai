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

using namespace std;

CameraView :: CameraView(ControllerInterface * _control, ModelInterface * _model)
{
	this->model = _model;
	this->control = _control;
	this->model->registerObserver((CameraView *)this);
	nameWindow = "JAVARI";
}

CameraView :: ~CameraView()
{
}

bool CameraView :: display()
{
	cv::Scalar GREEN(0, 255, 0), RED(0, 0, 255);
	/*
	int waitTime = 0, mode = 0, baseLine = 0;
	char key = 0;
	Setting& setting = Setting :: getInstance();

	//Initial mode
	if(setting.inputType == jvr::IMAGE_LIST)
	{
		mode = jvr::CAPTURING;
	}
	else
	{
		mode = jvr::DETECTION;
	}

	//Main loop
	for(;;)
	{
		view = setting.nextImage();
		//CHAMAR A CALIBRAÇÃO
		//...
		//model->calibration.executeCalibration(model, view);

		//Message Status
		if(mode == jvr::CAPTURING)
		{
			if(setting.showUndistorsed)
			{
				msg = cv::format( "x/%d Undist", setting.numFrameForCalibration);
				//msg = cv::format( "/%d Undist", (int)this->imagePoints.size(), setting->.numFrameForCalibration);
			}
			else
			{
				msg = cv::format( "x/%d", setting.numFrameForCalibration);
				//msg = cv::format( "%d/%d", (int)this->imagePoints.size(), this->settings.numFrameForCalibration);
			}
		}

		//Output text
		msg = (mode == jvr::CAPTURING) ? "100/100" : mode == jvr::CALIBRATED ? "Calibrated" : "Press 'g' to start";

		baseLine = 0;
		textSize = cv::getTextSize(msg, 1, 1, 1, &baseLine);
		cv::Point textOrigin(view.cols - 2 * textSize.width - 10, view.rows - 2 * baseLine - 10);

		cv::putText(view, msg, textOrigin, 1, 1, mode == jvr::CALIBRATED ?  GREEN : RED);
		if(mode == jvr::CALIBRATED && setting.showUndistorsed)
		{
			//TRANSFORMAR ISTO EM UM MÉTODO DA CLASSE CALIBRATION
			cv::Mat temp = view.clone();
			//cv::undistort(temp, view, this->cameraMatrix, this->distortionCoefficients);
		}

		cv::imshow(nameWindow, view);
		waitTime = settings.inputCapture.isOpened() ? 50 : settings.delayForVideoInput;

		key = (char)cv::waitKey(waitTime);

		if(key == jvr::ESC_KEY)
		{
			break;
		}

		if(key == 'u' && mode == jvr::CALIBRATED)
		{
			//Disparar a ação de distorcer
			setting.showUndistorsed = !settings.showUndistorsed;
		}

		if(settings.inputCapture.isOpened() && key == 'g')
		{
			//Disparar a ação de calibrar
			mode = jvr::CAPTURING;
			this->imagePoints.clear();
		}
	}
*/
	return true;
}

void CameraView :: update()
{

}
