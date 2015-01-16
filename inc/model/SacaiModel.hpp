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
		virtual bool startCalibration(cv::Mat * _view);

		/**
		 * @see ModelInterface
		 **/
		virtual bool resetPoint();

		/**
		 * @see ModelInterface
		 **/
		virtual bool startFindCircle(cv::Mat * _view);

		virtual int getMode()
		{
			return this->calibration->getMode();
		}
		virtual int getFrameElapse()
		{
			return this->calibration->getFrameElapse();
		}
		virtual bool getCalibrationDone()
		{
			return this->calibration->getCalibrationDone();
		}
		virtual int getRadius()
		{
			return this->recognizeCircle->getRadius();
		}
		virtual cv::Point * getCenter()
		{
			return this->recognizeCircle->getCenter();
		}

	private:
		Calibration * calibration;
		RecognizeCircle * recognizeCircle;
};

#endif
