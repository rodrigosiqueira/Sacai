/**
 * @file ModelInterface.hpp
 * @brief Keeps the class Subject for interface,
 **/
#ifndef _MODEL_INTERFACE_HPP_
#define _MODEL_INTERFACE_HPP_

#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>

#include <ViewInterface.hpp>

using namespace std;

class ViewInterface;
//namespace model
//{	
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

			virtual bool startCalibration(int * _mode, cv::Mat * _view, std::string * _message, int * _frameElapsed) = 0;
			virtual bool resetPoint() = 0;
			virtual bool getCalibrationDone()
			{
				return this->calibrationDone;
			}

		protected:
			vector<ViewInterface *> listOfObserver;
			string message;
			cv::Mat frame;
			cv::Size textSize;
			bool calibrationDone;

			ModelInterface();
			virtual ~ModelInterface();
	};
//};

#endif
