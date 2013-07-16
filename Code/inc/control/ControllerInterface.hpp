/**
 * @file ControllerInterface.hpp
 **/
#ifndef _CONTROLLER_INTERFACE_HPP_
#define _CONTROLLER_INTERFACE_HPP_

//#include <SacaiModel.hpp>
#include <opencv2/core/core.hpp>
class SacaiModel;

//namespace control
//{
	/**
	 * @class ControllerInterface
	 * @brief Abstract class that works in MVC pattern. This class was
	 * specialized in controller interface.
	 **/
	class ControllerInterface
	{
		public:
			virtual bool callCalibration() = 0;
			virtual bool showWindow(bool _show) = 0;
			virtual bool callResetPoint() = 0;

		protected:
			SacaiModel * modelSacai;
	};
//};

#endif
