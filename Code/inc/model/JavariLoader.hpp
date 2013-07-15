/**
 * @file JavariLoader.hpp
 **/

#ifndef _JAVARI_LOADER_HPP_
#define _JAVARI_LOADER_HPP_

#include <opencv2/core/core.hpp>

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
		virtual bool startCalibration(int _mode, cv::Mat * _view, string * _message);
		bool stopCalibration();

	private:
		JavariCommand * commandControl;
		Calibration * calibration;
		CalibrationStart * calibrationStartCommand;
		CalibrationStop * calibrationStopCommand;

		void buildLoader();
};

#endif
