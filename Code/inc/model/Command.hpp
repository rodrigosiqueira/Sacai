/**
 * @file Command.hpp
 **/
#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

/**
 * @class Command
 * @brief Abstract class responsible for commands execution in inherited
 * classes.
 **/
class Command
{
	public:
		/**
		 * @brief Execute method.
		 **/
		virtual void execute() = 0;

	protected:
		Command(){}
};

#endif
