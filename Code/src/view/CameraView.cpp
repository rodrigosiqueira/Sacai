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

CameraView :: CameraView(ControllerInterface * _control, ModelInterface * _model) : settings(Setting::getInstance())
{
	bool rc = false;

	this->modelView = _model;
	this->controlView = _control;
	this->frameElapsed = 0;
	nameWindow = "SACAI";

	rc = this->modelView->registerObserver(this);

	//Initial mode
	if(this->settings.inputType == util::IMAGE_LIST)
	{
		this->mode = util::CAPTURING;
	}
	else
	{
		this->mode = util::DETECTION;
	}
}

CameraView :: ~CameraView()
{}

bool CameraView :: display()
{
	cv::Scalar GREEN(0, 255, 0), RED(0, 0, 255);
	int waitTime = 0, baseLine = 0;
	char key = 0;
	cv::Size textSize;
	bool detectCircle = false;
	string circleMessage = "Press 'c' to find circle ";

	//Main loop
	for(;;)
	{
		this->frameView = this->settings.nextImage();
		//If calibration starts
		if(this->mode == util::CAPTURING)
		{
			this->controlView->callCalibration();
		}
		if(detectCircle)
		{
			this->controlView->callFindCircle();
		}

		//Output text
		if(this->mode == util::CAPTURING)
		{
			this->message = "100/100";
		}
		else if(this->mode == util::CALIBRATED)
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
		cv::Point textCircle(10, 10);

		if(this->mode == util::CAPTURING)
		{
			if(this->settings.showUndistorsed)
			{
				this->message = cv::format( "%d/%d Undist", this->frameElapsed, this->settings.numFrameForCalibration);
			}
			else
			{
				this->message = cv::format( "%d/%d", this->frameElapsed, this->settings.numFrameForCalibration);
			}
		}

		cv::putText(this->frameView, this->message, textOrigin, 1, 1, this->mode == util::CALIBRATED ?  GREEN : RED);
		cv::putText(this->frameView, circleMessage, textCircle, 1, 1, GREEN);

		cv::imshow(nameWindow, this->frameView);
		waitTime = settings.inputCapture.isOpened() ? 50 : settings.delayForVideoInput;

		key = (char)cv::waitKey(waitTime);

		if(key == util::ESC_KEY)
		{
			break;
		}

		if(key == 'u' && this->mode == util::CALIBRATED)
		{
			this->settings.showUndistorsed = !this->settings.showUndistorsed;
		}

		if(this->settings.inputCapture.isOpened() && key == 'g')
		{
			this->mode = util::CAPTURING;
			this->controlView->callResetPoint();
		}

		if(key == 'c')
		{
			detectCircle = !detectCircle;
		}
	}

	return true;
}

void CameraView :: update(int _mode, cv::Mat& _view, int _frameElapsed)
{
	this->mode = _mode;
	this->frameView = _view;
	this->frameElapsed = _frameElapsed;

	return;
}
