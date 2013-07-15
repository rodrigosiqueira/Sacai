/**
 * @file InputPattern.hpp
 * @brief Abstraction for the type of input. This class is a parth of
 * strategy pattern
 **/
#ifndef _INPUT_PATTERN_HPP_
#define _INPUT_PATTERN_HPP_

#include <Setting.hpp>
#include <opencv2/core/core.hpp>

/**
 * @class InputPattern
 * @brief This abtract class is a piece of Strategy pattern. It is the
 * base of other classes of patterns.
 **/
class InputPattern
{
	public:
		InputPattern()
		{}
		virtual ~InputPattern()
		{}
		/**
		 * @param[in] _source Receive the target frame for operation.
		 * @param[out] _output Output with points found in image.
		 * @param _sizePattern Size of the patters showed.
		 * @return Return true if pattern was found, otherwise return false.
		 * @brief This abtract method implements the operation of find
		 * 	geometry for calibration.
		 **/
		virtual bool findGeometry(
						cv::Mat& _source,
						vector<cv::Point2f>& _output,
						cv::Size& _sizePattern) = 0;
};

#endif
