/**
 * @file CirclesGrid.cpp
 **/
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <InputPattern.hpp>
#include <CirclesGrid.hpp>
#include <dataType.hpp>

CirclesGrid :: CirclesGrid() : InputPattern()
{

}

CirclesGrid :: ~CirclesGrid()
{

}

bool CirclesGrid :: findGeometry(
					cv::Mat& _source,
					vector<cv::Point2f>& _output,
					cv::Size& _sizePattern)
{

	bool found = false;
	cv::Mat viewGray;

	found = cv::findCirclesGrid(_source, _sizePattern, _output);

	return found;
}
