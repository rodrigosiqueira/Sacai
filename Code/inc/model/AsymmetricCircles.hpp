/**
 * @file AsymmetricCircles.hpp
 **/
#ifndef _ASYMMETRIC_CIRCLES_GRID_HPP_
#define _ASYMMETRIC_CIRCLES_GRID_HPP_

#include <opencv2/core/core.hpp>

#include <InputPattern.hpp>

//namespace model
//{
	/**
	 * @class AsymmetricCircles
	 * @brief Implements specific operation for find asymmetric circle grid.
	 **/
	class AsymmetricCircles : public InputPattern
	{
		public:
			AsymmetricCircles();
			virtual ~AsymmetricCircles();
			virtual bool findGeometry(
							cv::Mat& _source,
							vector<cv::Point2f>& _output,
							cv::Size& _sizePattern);
	};
//};

#endif

