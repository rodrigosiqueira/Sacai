/**
 * @file CalibrationStop.cpp
 **/

#include <CalibrationStop.hpp>

CalibrationStop :: CalibrationStop(Calibration * _calibration)
{
	this->calibration = _calibration;
}

CalibrationStop :: ~CalibrationStop()
{

}

void CalibrationStop :: execute()
{
	this->calibration->stopCalibration();
}
