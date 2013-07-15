/**
 * @file JavariController.hpp
 **/

#ifndef _JAVARI_CONTROLLER_HPP_
#define _JAVARI_CONTROLLER_HPP_

#include <JavariLoader.hpp>
#include <ViewInterface.hpp>
#include <ControllerInterface.hpp>
#include <CameraView.hpp>

/**
 * @class JavariController
 * @brief Keeps the reference for model class for execute actions. Note
 * that interface view call the methods of this class.
 **/
class JavariController : ControllerInterface
{
	public:
		/**
		 * @param _model Reference for model layer.
		 **/
		JavariController(JavariLoader * _model);
		virtual ~JavariController();

		virtual bool startCalibration();

	private:
		CameraView * view;
};

#endif
