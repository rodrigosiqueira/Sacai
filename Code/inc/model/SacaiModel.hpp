/**
 * @file SacaiModel.hpp
 **/

#ifndef _SACAI_LOADER_HPP_
#define _SACAI_LOADER_HPP_

#include <opencv2/core/core.hpp>

#include <ModelInterface.hpp>
#include <Calibration.hpp>

//namespace model
//{
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

			virtual bool startCalibration(
				int _mode,
				cv::Mat * _view,
				int _frameElapsed);

			virtual bool resetPoint();

		private:
			Calibration * calibration;
	};
//};

#endif
