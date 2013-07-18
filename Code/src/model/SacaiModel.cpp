/**
 * @file SacaiModel.cpp
 **/
#include <opencv2/core/core.hpp>

#include <Calibration.hpp>
#include <SacaiModel.hpp>

SacaiModel :: SacaiModel()
{
	this->calibration = new Calibration();
}

SacaiModel :: ~SacaiModel()
{
	delete this->calibration;
}

bool SacaiModel :: startCalibration(int _mode, cv::Mat * _view, int _frameElapsed)
{
	bool rc = false;

	if(_mode < 0 || !_view || _frameElapsed < 0)
	{
		return false;
	}

	this->modeCalibration = _mode;
	this->frameCalibration = _view;
	this->frameElapsedCalibration = _frameElapsed;

	//Execute calibration
	rc = this->calibration->executeCalibration(
			&(this->modeCalibration),
			this->frameCalibration,
			&(this->frameElapsedCalibration));
	//Notify all the observers
	this->updateObserver();

	return rc;
}

bool SacaiModel :: resetPoint()
{
	this->calibration->resetPoint();
	return true;
}
