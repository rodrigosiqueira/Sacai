/**
 * @file CalibrationStart.cpp
 **/

#include <CalibrationStart.hpp>
#include <Calibration.hpp>

CalibrationStart :: CalibrationStart(Calibration * _calibration)
{
	this->calibration = _calibration;
}

CalibrationStart :: ~CalibrationStart()
{
}

void CalibrationStart :: execute()
{
	this->calibration->executeCalibration();
}
