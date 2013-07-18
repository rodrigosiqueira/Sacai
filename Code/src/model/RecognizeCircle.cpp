/**
 * @file RecognizeCircle.cpp
 **/
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <RecognizeCircle.hpp>
#include <vector>

RecognizeCircle :: RecognizeCircle()
{}

RecognizeCircle :: ~RecognizeCircle()
{}

bool RecognizeCircle :: findCenter(cv::Mat * _source)
{
	cv::Mat grayImage;
	std::vector<cv::Vec3f> circles;
	size_t i = 0;

	cv::cvtColor((*_source), grayImage, cv::COLOR_BGR2GRAY);

	//Reduce the noise so we avoid false circle detection
	cv::GaussianBlur(grayImage, grayImage, cv::Size(9, 9), 2, 2 );

	cv::HoughCircles(
		grayImage,
		circles,
		CV_HOUGH_GRADIENT,
		1, grayImage.rows/8, 64, 70, 0, 0);

	// Draw the circles detected
	for(i = 0; i < circles.size(); i++ )
	{
		cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// circle center
		cv::circle((*_source), center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
		// circle outline
		cv::circle((*_source), center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
	}

	return true;
}
