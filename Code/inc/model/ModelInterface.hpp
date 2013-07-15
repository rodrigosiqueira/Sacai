/**
 * @file ModelInterface.hpp
 * @brief Keeps the class Subject for interface,
 **/
#ifndef _MODEL_INTERFACE_HPP_
#define _MODEL_INTERFACE_HPP_

#include <iostream>
#include <vector>

#include <ViewInterface.hpp>

using namespace std;

class ViewInterface;
/**
 * @class ModelInterface
 * @brief Interface for model with methods for pattern Observer. This
 * class represent the Subject in pattern observer. 
 **/
class ModelInterface
{
	public:
		/**
		 * @param _observer Reference for object that would be register.
		 * @brief This method belongs for Pattern Observer. It register
		 * the observer of actions.
		 **/
		void registerObserver(ViewInterface * _observer);
		/**
		 * @brief Update all observers.
		 **/
		void updateObserver();

	protected:
		vector<ViewInterface *> listOfObserver;

		ModelInterface();
		virtual ~ModelInterface();
};

#endif
