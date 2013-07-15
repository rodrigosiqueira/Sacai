/**
 * @file CameraView.hpp
 **/
#ifndef _CAMERA_VIEW_HPP_
#define _CAMERA_VIEW_HPP_

#include <opencv2/core/core.hpp>
#include <iostream>

#include <ViewInterface.hpp>
#include <ControllerInterface.hpp>
#include <ModelInterface.hpp>

using namespace std;

/**
 * @class CameraView
 * @brief Concrete class that handles display camera and specific operation.
 **/
class CameraView : public ViewInterface
{
	public:
		/**
		 * @param _control Reference for control class. This parameter is
		 * used for doing interface action.
		 * @param _model Reference for model. This keeps interface updated.
		 * @brief This construct receives the maily elements for doing interface
		 * operation.
		 **/
		CameraView(ControllerInterface * _control, ModelInterface * _model);
		virtual ~CameraView();

		virtual bool display();
		virtual void update(string _message, cv::Mat _frame, cv::Size _textSize);

	private:
		bool operation;
		string nameWindow, message;
		cv::Mat frameView;
		cv::Size textSize;
};

#endif
