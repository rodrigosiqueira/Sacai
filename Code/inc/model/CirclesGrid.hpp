/**
 * @file CirclesGrid.hpp
 **/
#ifndef _CIRCLES_GRID_HPP_
#define _CIRCLES_GRID_HPP_

/**
 * @class CirclesGrid
 * @brief Implements specific operation for find circle grid.
 **/
class CirclesGrid : InputPattern
{
	public:
		CirclesGrid();
		virtual ~CirclesGrid();
		virtual bool findGeometry(
						cv::Mat& _source,
						vector<cv::Point2f>& _output,
						cv::Size& _sizePattern);
};

#endif
