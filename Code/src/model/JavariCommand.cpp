/**
 * @file JavariCommand.hpp
 **/

#include <iostream>
#include <JavariCommand.hpp>
#include <Command.hpp>
#include <NoCommand.hpp>
#include <dataType.hpp>

using namespace std;

JavariCommand :: JavariCommand()
{
}

JavariCommand :: ~JavariCommand()
{
}

void JavariCommand :: setCommand(unsigned int _slot, Command * _start, Command * _stop)
{
	this->startCommand.push_back(_start);
	this->stopCommand.push_back(_stop);
}

void JavariCommand :: startCommandWasActivated(unsigned int _slot)
{
	this->startCommand.at(_slot)->execute();
}

void JavariCommand :: stopCommandWasActivated(unsigned int _slot)
{
	this->stopCommand.at(_slot)->execute();
}
