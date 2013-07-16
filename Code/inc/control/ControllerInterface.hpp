/**
 * @file ControllerInterface.hpp
 **/
#ifndef _CONTROLLER_INTERFACE_HPP_
#define _CONTROLLER_INTERFACE_HPP_

//#include <SacaiLoader.hpp>
#include <opencv2/core/core.hpp>
class SacaiLoader;

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
			virtual bool callCalibration(int _mode, cv::Mat * _view, std::string * _message) = 0;

		protected:
			SacaiLoader * modelSacai;
	};
//};

#endif
