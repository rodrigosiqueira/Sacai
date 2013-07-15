/**
 * @file ChessBoard.hpp
 **/
#ifndef _CHESSBOARD_HPP_
#define _CHESSBOARD_HPP_

#include <InputPattern.hpp>

//namespace model
//{
	/**
	 * @class ChessBoard
	 * @brief Implements the specific operations for find chess pattern.
	 **/
	class ChessBoard : public InputPattern
	{
		public:
			ChessBoard();
			virtual ~ChessBoard();
			virtual bool findGeometry(
							cv::Mat& _source,
							vector<cv::Point2f>& _output,
							cv::Size& _sizePattern);
	};
//};

#endif
