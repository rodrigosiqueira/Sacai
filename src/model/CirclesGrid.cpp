/**
 * @file CirclesGrid.cpp
 **/
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <InputPattern.hpp>
#include <CirclesGrid.hpp>

CirclesGrid :: CirclesGrid() : InputPattern()
{}

CirclesGrid :: ~CirclesGrid()
{}

bool CirclesGrid :: findGeometry(
					cv::Mat& _source,
					std::vector<cv::Point2f>& _output,
					cv::Size& _sizePattern)
{
	bool found = false;
	cv::Mat viewGray;

	if(_source.empty() || _output.empty())
	{
		return false;
	}

	found = cv::findCirclesGrid(_source, _sizePattern, _output);

	return found;
}
