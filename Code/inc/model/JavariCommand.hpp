/**
 * @file JavariCommand.hpp
 **/
#ifndef _JAVARI_COMMAND_HPP_
#define _JAVARI_COMMAND_HPP_

#include <Command.hpp>
#include <vector>

using namespace std;

/**
 * @class JavariCommand
 * @brief Encapsulate commands.
 **/
class JavariCommand
{
	public:
		vector<Command *> startCommand;
		vector<Command *> stopCommand;

		JavariCommand();
		virtual ~JavariCommand();

		/**
		 * @param _slot Indicates the code form command.
		 * @param _start Reference for class associate to _slot.
		 * @param _stop Reference for class associate to _slot.
		 * @brief Configure the class loader with the actions.
		 **/
		void setCommand(unsigned int _slot, Command * _start, Command * _stop);

		/**
		 * @param _slot Command that would like to execute.
		 * @brief Start command based on slot.
		 **/
		void startCommandWasActivated(unsigned int _slot);

		/**
		 * @param _slot Command that would linke to stop.
		 * @brief Stop command based on slot.
		 **/
		void stopCommandWasActivated(unsigned int _slot);
};

#endif
