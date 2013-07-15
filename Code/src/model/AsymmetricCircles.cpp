/**
 * @file AsymmetricCircles.cpp
 **/
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <InputPattern.hpp>
#include <AsymmetricCircles.hpp>
#include <dataType.hpp>

AsymmetricCircles :: AsymmetricCircles() : InputPattern()
{

}

AsymmetricCircles :: ~AsymmetricCircles()
{

}

bool AsymmetricCircles :: findGeometry(
					cv::Mat& _source,
					vector<cv::Point2f>& _output,
					cv::Size& _sizePattern)
{

	bool found = false;
	cv::Mat viewGray;

	found = cv::findCirclesGrid(_source, _sizePattern, _output, cv::CALIB_CB_ASYMMETRIC_GRID);

	return found;
}
