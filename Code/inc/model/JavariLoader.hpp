/**
 * @file JavariLoader.hpp
 **/

#ifndef _JAVARI_LOADER_HPP_
#define _JAVARI_LOADER_HPP_

#include <ModelInterface.hpp>
#include <Calibration.hpp>
#include <CalibrationStart.hpp>
#include <CalibrationStop.hpp>
#include <JavariCommand.hpp>

/**
 * @class JavariLoader
 * @brief This class encapsulate the many actions in commands.
 **/

class JavariLoader : public ModelInterface
{
	public:
		JavariLoader();
		virtual ~JavariLoader();
		bool startCalibration();
		bool stopCalibration();

	private:
		JavariCommand * commandControl;
		Calibration * calibration;
		CalibrationStart * calibrationStartCommand;
		CalibrationStop * calibrationStopCommand;

		void buildLoader();
};

#endif
