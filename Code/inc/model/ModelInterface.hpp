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
		bool registerObserver(ViewInterface * _observer);
		/**
		 * @brief Update all observers.
		 **/
		void updateObserver();
		/**
		 * @param _mode Current mode of calibration.
		 * @param _view Target frame for calibration.
		 * @param _frameElapsed Total of frame elapsed.
		 * @return Return true if all right and false otherwise
		 * @brief Method that encapsulate the action of call calibration
		 **/
		virtual bool startCalibration(int _mode, cv::Mat * _view, int _frameElapsed) = 0;
		/**
		 * @return Return true if all right, and false otherwise.
		 * @brief Reset the vector of points.
		 **/
		virtual bool resetPoint() = 0;

	protected:
		std::vector<ViewInterface *> listOfObserver;	/**< List of observers that model knows.*/
		cv::Mat * frameCalibration;	/**< Frame used for update observers in calibration.*/
		int modeCalibration;		/**< Current mode of calibration.*/
		int frameElapsedCalibration;/**< Total of frame elaspsed for calibration.*/

		ModelInterface();
		virtual ~ModelInterface();
};

#endif
