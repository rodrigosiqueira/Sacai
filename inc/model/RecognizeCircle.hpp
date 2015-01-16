/**
 * @file RecognizeCircle.hpp
 **/
#ifndef _RECOGNIZE_CIRCLE_HPP_
#define _RECOGNIZE_CIRCLE_HPP_

#include <opencv2/core/core.hpp>

/**
 * @class RecognizeCircle
 **/
class RecognizeCircle
{
	public:
		RecognizeCircle();
		virtual ~RecognizeCircle();
		/**
		 * @param[in] _source Picture to analyze.
		 * @return Return true if all right or false otherwise.
		 * @brief This method try to find out a circle pattern in the
		 * image with Hough transform.
		 **/
		bool findCenter(cv::Mat * _source);
		inline int getRadius()
		{
			return this->radius;
		}
		inline cv::Point * getCenter()
		{
			return &this->center;
		}

	private:
		int radius;
		cv::Point center;
};

#endif 
