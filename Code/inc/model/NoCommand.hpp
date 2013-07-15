/**
 * @file NoCommand.hpp
 **/
#ifndef _NO_COMMAND_HPP_
#define _NO_COMMAND_HPP_

#include <Command.hpp>

/**
 * @class NoCommand
 * @brief No command for initialize object.
 **/
class NoCommand : public Command
{
	public:
		virtual void execute(){}
};

#endif
