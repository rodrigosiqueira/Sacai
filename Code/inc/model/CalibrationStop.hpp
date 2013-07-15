/**
 * @file CalibrationStop.hpp
 **/
#ifndef _CALIBRATION_STOP_HPP_
#define _CALIBRATION_STOP_HPP_

#include <Command.hpp>
#include <Calibration.hpp>

/**
 * @class CalibrationStop
 * @brief Encapsulate stop action
 **/
class CalibrationStop : public Command
{
	public:
		/**
		 * @param _calibration Reference to Calibration class.
		 **/
		CalibrationStop(Calibration * _calibration);
		virtual ~CalibrationStop();
		virtual void execute();

	private:
		Calibration * calibration;
};

#endif
