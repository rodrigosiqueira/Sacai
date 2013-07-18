/**
 * @file ControllerInterface.hpp
 **/
#ifndef _CONTROLLER_INTERFACE_HPP_
#define _CONTROLLER_INTERFACE_HPP_

#include <opencv2/core/core.hpp>

class SacaiModel;
/**
 * @class ControllerInterface
 * @brief Abstract class that works in MVC pattern. This class was
 * specialized in controller interface.
 * @see SacaiModel
 **/
class ControllerInterface
{
	public:
		/**
		 * @return Return true if all right, and false otherwise.
		 * @brief Encapsulate the execution of calibration. 
		 **/
		virtual bool callCalibration() = 0;
		/**
		 * @return Return true if all right and false otherwise.
		 * @brief Display de window.
		 **/
		virtual bool showWindow(bool _show) = 0;
		/**
		 * @brief Reset the points of calibration.
		 **/
		virtual bool callResetPoint() = 0;

	protected:
		SacaiModel * modelSacai;	/**< Reference to model interface*/
};

#endif
