/**
 * @file ViewInterface.hpp
 **/
#ifndef _VIEW_INTERFACE_HPP_
#define _VIEW_INTERFACE_HPP_

#include <ModelInterface.hpp>
#include <ControllerInterface.hpp>

class ModelInterface;
class ControllerInterface;
/**
 * @class ViewInterface
 * @brief Abstract class used in MVC which Subject. 
 **/
class ViewInterface
{
	public:
		/**
		 * @brief Update image for specific situation.
		 **/
		virtual void update() = 0;
		/**
		 * @return If all right return true, otherwise false.
		 * @brief Implements specific visualization.
		 **/
		virtual bool display() = 0;

	protected:
		ModelInterface * model;
		ControllerInterface * control;

		ViewInterface(){}
		virtual ~ViewInterface(){}
};

#endif
