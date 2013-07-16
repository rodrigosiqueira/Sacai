/**
 * @file CameraView.hpp
 **/
#ifndef _CAMERA_VIEW_HPP_
#define _CAMERA_VIEW_HPP_

#include <iostream>

#include <opencv2/core/core.hpp>

#include <ViewInterface.hpp>
#include <ControllerInterface.hpp>
#include <ModelInterface.hpp>

using namespace std;

//namespace view
//{
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
			virtual void update(int _mode, cv::Mat * _view, std::string * _message);

		private:
			bool operation;
			string nameWindow, message;
			cv::Mat frameView;
			cv::Size textSize;
	};
//}

#endif
