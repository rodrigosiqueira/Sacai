/**
 * @file SacaiModel.hpp
 **/
#ifndef _SACAI_LOADER_HPP_
#define _SACAI_LOADER_HPP_

#include <opencv2/core/core.hpp>

#include <ModelInterface.hpp>
#include <Calibration.hpp>
#include <RecognizeCircle.hpp>

/**
 * @class SacaiModel
 * @brief Concrete implementation of "Model" Interface. This class
 * encapsulate many actions and the management of observers.
 * @see ModelInterface
 **/
class SacaiModel : public ModelInterface
{
	public:
		SacaiModel();
		virtual ~SacaiModel();

		/**
		 * @see ModelInterface
		 **/
		virtual bool startCalibration(
			int _mode,
			cv::Mat * _view,
			int _frameElapsed);

		/**
		 * @see ModelInterface
		 **/
		virtual bool resetPoint();

		/**
		 * @see ModelInterface
		 **/
		virtual bool startFindCircle(int _mode, cv::Mat * _view, int _frameElapsed);

	private:
		Calibration * calibration;
		RecognizeCircle * recognizeCircle;
};

#endif
