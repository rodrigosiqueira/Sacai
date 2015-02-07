/**
 * @file ChessBoard.hpp
 **/
#ifndef _CHESSBOARD_HPP_
#define _CHESSBOARD_HPP_

#include <vector>

#include "InputPattern.hpp"

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
      std::vector<cv::Point2f>& _output,
      cv::Size& _sizePattern);
};

#endif
