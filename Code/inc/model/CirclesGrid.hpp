/**
 * @file CirclesGrid.hpp
 **/
#ifndef _CIRCLES_GRID_HPP_
#define _CIRCLES_GRID_HPP_

#include <vector>

/**
 * @class CirclesGrid
 * @brief Implements specific operation for find circle grid.
 * @see InputPattern
 **/
class CirclesGrid : public InputPattern
{
	public:
		CirclesGrid();
		virtual ~CirclesGrid();
		virtual bool findGeometry(
					cv::Mat& _source,
					std::vector<cv::Point2f>& _output,
					cv::Size& _sizePattern);
};

#endif
