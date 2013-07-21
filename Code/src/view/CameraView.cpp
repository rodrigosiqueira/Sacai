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

static void stringMenu(
	cv::Mat& _frame,
	int _mode,
	int _frameElapsed,
	int _totalFrame = 100,
	int _undistortion = 0)
{
	string circleMessage, calibrationMessage;
	int baseLine = 0;
	cv::Size textSize;
	cv::Point textOrigin, textCircle;
	cv::Scalar GREEN(0, 255, 0), RED(0, 0, 255);

	//Find circle
	circleMessage = "Press 'c' to detect circles";

	//Output text
	switch(_mode)
	{
		case util::CAPTURING:
			calibrationMessage = "100/100";
			if(_undistortion)
			{
				calibrationMessage = cv::format("%d/%d Undist", _frameElapsed, _totalFrame);
			}
			else
			{
				calibrationMessage = cv::format( "%d/%d", _frameElapsed, _totalFrame);
			}
			break;
		case util::CALIBRATED:
			calibrationMessage = "Calibrated";
			break;
		default:
			calibrationMessage = "Press 'g' to start";
			break;
	}

	textSize = cv::getTextSize(calibrationMessage, 1, 1, 1, &baseLine);
	//Calibration menu position
	textOrigin.x = _frame.cols - 2 * textSize.width - 10;
	textOrigin.y = _frame.rows - 2 * baseLine - 10;
	cv::putText(_frame, calibrationMessage, textOrigin, 1, 1, (_mode == util::CALIBRATED) ?  GREEN : RED);

	//Circle menu
	baseLine = 0;
	textSize = cv::getTextSize(circleMessage, 1, 1, 1, &baseLine);
	textCircle.x = textOrigin.x;
	textCircle.y = textOrigin.y - 20;
	cv::putText(_frame, circleMessage, textCircle, 1, 1, GREEN);

	return;
}

bool CameraView :: display()
{
	int waitTime = 0;
	char key = 0;
	bool detectCircle = false;

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
		stringMenu(this->frameView,
					this->mode,
					this->frameElapsed,
					this->settings.numFrameForCalibration,
					this->settings.showUndistorsed);

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
