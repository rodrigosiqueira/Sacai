/**
 * @file SacaiController.hpp
 **/

#ifndef _SACAI_CONTROLLER_HPP_
#define _SACAI_CONTROLLER_HPP_

#include <opencv2/core/core.hpp>

#include <SacaiModel.hpp>
#include <ControllerInterface.hpp>
#include <CameraView.hpp>

//namespace control
//{
	/**
	 * @class SacaiController
	 * @brief Keeps the reference for model class for execute actions. Note
	 * that interface view call the methods of this class.
	 **/
	class SacaiController : public ControllerInterface
	{
		public:
			/**
			 * @param _model Reference for model layer.
			 **/
			SacaiController(SacaiModel * _model);
			virtual ~SacaiController();

			virtual bool callCalibration();
			
			virtual bool showWindow(bool _show);
			virtual bool callResetPoint();

		private:
			CameraView * viewSacai;
	};
//}

#endif
