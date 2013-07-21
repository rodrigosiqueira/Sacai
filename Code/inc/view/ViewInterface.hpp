/**
 * @file ViewInterface.hpp
 **/
#ifndef _VIEW_INTERFACE_HPP_
#define _VIEW_INTERFACE_HPP_

#include <string>

#include <opencv2/core/core.hpp>

#include <ModelInterface.hpp>
#include <ControllerInterface.hpp>

using namespace std;

class ModelInterface;
class ControllerInterface;

//namespace view
//{
	/**
	 * @class ViewInterface
	 * @brief Abstract class used in MVC pattern. This class represents
	 * the interface for observers, in this case the GUI.
	 **/
	class ViewInterface
	{
		public:
			/**
			 * @param _mode Current Mode of operation of calibration.
			 * @param _view Target Frame used in some operation.
			 * @param _frameElapsed Number of frames computed.
			 * @brief This method is a part of "Observer pattern", it
			 * represents the observer. Basically, this observer update the screen.
			 **/
			//virtual void update(int _mode, cv::Mat& _view, int _frameElapsed) = 0;
			virtual void update(cv::Mat& _view) = 0;
			/**
			 * @return If all right return true, otherwise false.
			 * @brief Implements specific visualization.
			 **/
			virtual bool display() = 0;
			/**
			 * @return Current reference to frame.
			 * @brief Commonly used for return the reference for make some
			 * modifications in current frame by another method.
			 **/
			virtual cv::Mat * getFrame() = 0;

		protected:
			ModelInterface * modelView;			/**< Reference to model.*/
			ControllerInterface * controlView;	/**< Reference to control.*/

			ViewInterface(){}
			virtual ~ViewInterface(){}
	};
//};

#endif
