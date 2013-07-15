/**
 * @file ControllerInterface.hpp
 **/
#ifndef _CONTROLLER_INTERFACE_HPP_
#define _CONTROLLER_INTERFACE_HPP_

#include <ModelInterface.hpp>

//Avoid Circular depedency
class JavariLoader;
/**
 * @class ControllerInterface
 * @brief Abstract class that works in MVC pattern. This class was
 * specialized in controller interface.
 **/
class ControllerInterface
{
	public:
		/**
		 * @return If all right return true, otherwise false.
		 * @brief Call the methods that execute calibration.
		 **/
		//virtual bool startCalibration() = 0;

	protected:
		JavariLoader * model;
		ControllerInterface()
		{}
};

#endif
