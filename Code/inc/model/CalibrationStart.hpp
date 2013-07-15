/**
 * @file CalibrationStart.hpp
 **/
#ifndef _CALIBRATION_START_HPP_
#define _CALIBRATION_START_HPP_

#include <Command.hpp>
#include <Calibration.hpp>

/**
 * @class CalibrationStart
 * @brief Encapsulate Command that start calibration.
 * */
class CalibrationStart : public Command
{
	public:
		/**
		 * @param _calibration Reference for calibration.
		 **/
		CalibrationStart(Calibration * _calibration);
		virtual ~CalibrationStart();

		virtual void execute();

	private:
		Calibration * calibration;
};

#endif
