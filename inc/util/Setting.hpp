/**
 * @file Setting.hpp
 * @brief Definition of class Setting. 
 **/

#ifndef _SETTING_HPP_
#define _SETTING_HPP_

#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "dataType.hpp"

using namespace std;

//namespace util
//{
  /**
  * @class Setting
  * @brief Handling the input file with configuration, write one file with
  * settings, and make some configurations.
  **/
  class Setting
  {
    public:
      cv::Size boardSize; /**< Number of inner corners per a item row and column.*/
      util::Pattern calibrationPattern; /**< Chessboard, circles, or asymmetric.*/
      float squareSize; /**< The size of square in your defined unit.*/
      int numFrameForCalibration; /**< Number of frames to use from the input for calibration. */
      float aspectRatio;
      int delayForVideoInput;
      bool writePoint; /**< Write to the output file the feature points.*/
      bool writeExtrinsics;
      bool calibZeroTangDistortion;
      bool calibFixPrincipalPoint;
      bool flipAroundHorizonAxis;
      string outputFileName;
      bool showUndistorsed;
      string input;

      int cameraId;
      vector<string> imageList;
      int atImageList;
      cv::VideoCapture inputCapture;
      util::InputType inputType;
      bool goodInput; /**< Test if everything is all right with input.*/
      int flag;

      virtual ~Setting();

      static Setting& getInstance()
      {
        static Setting instance;
        return instance;
      }

      bool loadCalibrationFile(string _path);

      /**
      * @param
      * @brief
      **/
      void write(cv::FileStorage& _fileStorage) const;

      /**
      * @param
      * @brief
      **/
      void read(const cv::FileNode& _node);

      /**
      * @return Return next frame.
      * @brief Capture the next frame and return it.
      **/
      cv::Mat nextImage();

    private:
      Setting();
      string patternToUse;

      /**
      * @brief
      **/
      void interpret();
  };
//};

#endif
