/**
 * @file Setting.cpp
 * @brief Keeps some function that doing some operations with files. This
 * code was based on openCv Documentation.
 **/
#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include "Setting.hpp"

using namespace std;

Setting :: ~Setting()
{}

static bool readStringList(const string& _fileName, vector<string>& _list)
{
  _list.clear();
  
  cv::FileStorage fileStorage(_fileName, cv::FileStorage::READ);
  if(!fileStorage.isOpened())
  {
    return false;
  }
  
  cv::FileNode node = fileStorage.getFirstTopLevelNode();
  if(node.type() != cv::FileNode::SEQ)
  {
    return false;
  }

  cv::FileNodeIterator it = node.begin(), it_end = node.end();
  for( ; it != it_end; ++it )
  {
    _list.push_back((string)*it);
  }

  return true;
}

Setting :: Setting()
{
  this->calibrationPattern = util::NOT_EXISTING;
  this->squareSize = 0;
  this->numFrameForCalibration = 7;
  this->aspectRatio = 1;
  this->delayForVideoInput = 100;
  this->writePoint = false;
  this->writeExtrinsics = false;
  this->calibZeroTangDistortion = false;
  this->calibFixPrincipalPoint = false;
  this->flipAroundHorizonAxis = false;
  this->outputFileName = "cameraCalibration.yaml";
  this->input = "0";
  this->cameraId = 0;
  this->atImageList = 0;
  this->inputType = util::INVALID;
  this->goodInput = false;
  this->flag = 0;
}

bool Setting :: loadCalibrationFile(string _pathSetting)
{
  Setting& settings = Setting :: getInstance();
  cv::FileStorage fileWithSettings;

  if(_pathSetting.empty())
  {
    cout << "Error in locationFile" << endl;
    return false;
  }
  //Open File and test the result
  fileWithSettings.open(_pathSetting, cv::FileStorage::READ);

  if(!fileWithSettings.isOpened())
  {
    cout << "Could not open the configuration file: " << _pathSetting;
    return false;
  }
  //Copy the parameters in file configuration to class.
  this->read(fileWithSettings["Settings"]);
  fileWithSettings.release();

  //Verify if all right with input.
  if(!settings.goodInput)
  {
    cout << "Invalid input detected." << endl;
    return false;
  }

  return true;
}

void Setting :: write(cv::FileStorage& _fileStorage) const
{
  _fileStorage
    << "{"	<< "BoardSize_Width"	<< this->boardSize.width
        << "BoardSize_Height"	<< this->boardSize.height
        << "Square_Size"		<< this->squareSize
        << "Calibrate_Pattern"	<< this->patternToUse
        << "Calibrate_NrOfFrameToUse"	<< this->numFrameForCalibration
        << "Calibrate_FixAspectRation"	<< this->aspectRatio
        << "Calibrate_AssumeZeroTangentialDistortion" << this->calibZeroTangDistortion
        << "Calibrate_FixPrincipalPointAtTheCenter" << this->calibFixPrincipalPoint
        << "Write_DetectedFeaturePoints" << this->writePoint
        << "Write_extrinsicParameters" << this->writeExtrinsics
        << "Write_outputFileName" << this->outputFileName
        << "Show_UndistortedImage" << this->showUndistorsed
        << "Input_FlipAroundHorizontalAxis" << this->flipAroundHorizonAxis
        << "Input_Delay" << this->delayForVideoInput
        << "Input" << input
    << "}";

  return;
}

void Setting :: read(const cv::FileNode& _node)
{
  _node["BoardSize_Width"] >> this->boardSize.width;
  _node["BoardSize_Height"] >> this->boardSize.height;
  _node["Calibrate_Pattern"] >> this->patternToUse;
  _node["Square_Size"] >> this->squareSize;
  _node["Calibrate_NrOfFrameToUse"] >> this->numFrameForCalibration;
  _node["Calibrate_FixAspectRatio"] >> this->aspectRatio;
  _node["Write_DetectedFeaturePoints"] >> this->writePoint;
  _node["Write_extrinsicParameters"] >> this->writeExtrinsics;
  _node["Write_outputFileName"] >> this->outputFileName;
  _node["Calibrate_AssumeZeroTangentialDistortion"] >> this->calibZeroTangDistortion;
  _node["Calibrate_FixPrincipalPointAtTheCenter"] >> this->calibFixPrincipalPoint;
  _node["Input_FlipAroundHorizontalAxis"] >> this->flipAroundHorizonAxis;
  _node["Show_UndistortedImage"] >> this->showUndistorsed;
  _node["Input"] >> this->input;
  _node["Input_Delay"] >> this->delayForVideoInput;
  this->interpret();

  return;
}

void Setting :: interpret()
{
  this->goodInput = true;
  if(this->boardSize.width <= 0 || this->boardSize.height <= 0)
  {
    cerr << "Invalid Board size: " << this->boardSize.width 
          << " " << this->boardSize.height << endl;
    this->goodInput = false;
  }

  if(this->squareSize <= 10e-6)
  {
    cerr << "Invalid square size: " << this->squareSize << endl;
    this->goodInput = false;
  }

  if(this->numFrameForCalibration <= 0)
  {
    cerr << "Invalid number of frame" << numFrameForCalibration << endl;
    goodInput = false;
  }

  if(this->input.empty())
  {
    inputType = util::INVALID;
  }
  else
  {
    //Camera
    if(this->input[0] >= '0' && this->input[0] <= '9')
    {
      stringstream strStream(this->input);
      strStream >> this->cameraId;
      this->inputType = util::CAMERA;
    }
    else
    {
      //List of image
      if(readStringList(this->input, this->imageList))
      {
        this->inputType = util::IMAGE_LIST;
        this->numFrameForCalibration =
          (this->numFrameForCalibration < (int)this->imageList.size()
            ? this->numFrameForCalibration
            : (int)this->imageList.size());
      }
      else
      {
        this->inputType = util::VIDEO_FILE;
      }
    }
    //Open 
    if(this->inputType == util::CAMERA)
    {
      this->inputCapture.open(this->cameraId);
      //this->inputCapture.set(CV_CAP_PROP_FRAME_WIDTH, 580);
      //this->inputCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 334);
    }
    else if(this->inputType == util::VIDEO_FILE)
    {
      this->inputCapture.open(this->input);
    }
    else if(this->inputType != util::IMAGE_LIST && 
            !this->inputCapture.isOpened())
    {
      this->inputType = util::INVALID;
    }
  }

  if(this->inputType == util::INVALID)
  {
    cerr << "Inexistent input: " << this->input;
    goodInput = false;
  }
  //Configure input flag
  this->flag = 0;

  if(this->calibFixPrincipalPoint)
  {
    this->flag |= CV_CALIB_FIX_PRINCIPAL_POINT;
  }

  if(this->calibZeroTangDistortion)
  {
    this->flag |= CV_CALIB_ZERO_TANGENT_DIST;
  }

  if(this->aspectRatio)
  {
    this->flag |= CV_CALIB_FIX_ASPECT_RATIO;
  }

  this->calibrationPattern = util::NOT_EXISTING;
  if(!this->patternToUse.compare("CHESSBOARD"))
  {
    this->calibrationPattern = util::CHESSBOARD;
  }
  else if(!this->patternToUse.compare("CIRCLES_GRID"))
  {
    this->calibrationPattern = util::CIRCLES_GRID;
  }
  else if(!this->patternToUse.compare("ASYMMETRIC_CIRCLES_GRID"))
  {
    this->calibrationPattern = util::ASYMMETRIC_CIRCLES_GRID;
  }

  if(this->calibrationPattern == util::NOT_EXISTING)
  {
    cerr << " Inexistent camera calibration mode: " << patternToUse << endl;
    goodInput = false;
  }
  this->atImageList = 0;

  return;
}

cv::Mat Setting :: nextImage()
{
  cv::Mat result, view;

  if(this->inputCapture.isOpened())
  {
    this->inputCapture >> view;
    view.copyTo(result);
  }
  else if(this->atImageList < (int)this->imageList.size())
  {
    result = cv::imread(this->imageList[this->atImageList++], 
                        CV_LOAD_IMAGE_COLOR);
  }

  return result;
}
