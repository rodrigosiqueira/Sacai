/**
 * @file JavariLoader.cpp
 **/
#include <opencv2/core/core.hpp>

#include <JavariLoader.hpp>
#include <dataType.hpp>

JavariLoader :: JavariLoader()
{
	this->commandControl = new JavariCommand();
	this->calibration = new Calibration();
	this->calibrationStartCommand = new CalibrationStart(this->calibration);
	this->calibrationStopCommand = new CalibrationStop(this->calibration);

	this->buildLoader();
}

JavariLoader :: ~JavariLoader()
{
	delete this->commandControl;
	delete this->calibration;
	delete this->calibrationStartCommand;
}

bool JavariLoader :: startCalibration(int _mode, cv::Mat * _view, string * _message)
{
	this->calibration->setParam(_mode, _view, _message);
	this->commandControl->startCommandWasActivated(jvr::CALIBRATION_COMMAND);
	this->updateObserver();

	return true;
}

bool JavariLoader :: stopCalibration()
{
	this->commandControl->stopCommandWasActivated(jvr::CALIBRATION_COMMAND);
	return true;
}

void JavariLoader :: buildLoader()
{
	this->commandControl->setCommand(jvr::CALIBRATION_COMMAND, this->calibrationStartCommand, this->calibrationStopCommand);
}
