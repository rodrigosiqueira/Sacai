/**
 * @file ChessBoard.cpp
 **/
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <InputPattern.hpp>
#include <ChessBoard.hpp>
#include <dataType.hpp>

ChessBoard :: ChessBoard() : InputPattern()
{}

ChessBoard :: ~ChessBoard()
{}

bool ChessBoard :: findGeometry(
					cv::Mat& _source,
					std::vector<cv::Point2f>& _output,
					cv::Size& _sizePattern)
{
	bool found = false;
	cv::Mat viewGray;

	found = cv::findChessboardCorners(
			_source,
			_sizePattern,
			_output,
			CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FAST_CHECK | CV_CALIB_CB_NORMALIZE_IMAGE);

	//Improve the found corners coordinate for chessboard
	if(found)
	{
		cv::cvtColor(_source, viewGray, CV_BGR2GRAY);
		cv::cornerSubPix(
			viewGray, 
			_output,
			cv::Size(11,11),
			cv::Size(-1, -1),
			cv::TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));
		return true;
	}
	else
	{
		return false;
	}
}
