/**
 * @file SacaiLoader.hpp
 **/

#ifndef _SACAI_LOADER_HPP_
#define _SACAI_LOADER_HPP_

#include <opencv2/core/core.hpp>

#include <ModelInterface.hpp>
#include <Calibration.hpp>

//namespace model
//{
	/**
	 * @class SacaiLoader
	 * @brief This class encapsulate the many actions in commands.
	 **/
	class SacaiLoader : public ModelInterface
	{
		public:
			Calibration * calibration;

			SacaiLoader();
			virtual ~SacaiLoader();

			virtual bool startCalibration(
				int * _mode,
				cv::Mat * _view,
				std::string * _message,
				int * _frameElapsed);
			virtual bool resetPoint();
	};
//};

#endif
