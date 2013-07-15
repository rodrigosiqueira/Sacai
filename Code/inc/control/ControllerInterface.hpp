/**
 * @file ControllerInterface.hpp
 **/
#ifndef _CONTROLLER_INTERFACE_HPP_
#define _CONTROLLER_INTERFACE_HPP_

//#include <SacaiLoader.hpp>

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
		protected:
			SacaiLoader * modelSacai;
	};
//};

#endif
