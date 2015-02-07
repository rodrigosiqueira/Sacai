/**
 * @file SacaiLoader.cpp
 **/
#include <opencv2/core/core.hpp>

#include "Calibration.hpp"
#include "SacaiLoader.hpp"

SacaiLoader :: SacaiLoader()
{
  this->calibration = new Calibration();
  //this->calibrationDone = false;
  this->calibration->calibrationDone = false;
}

SacaiLoader :: ~SacaiLoader()
{
  delete this->calibration;
}

bool SacaiLoader :: startCalibration(int * _mode, cv::Mat * _view, 
                                     std::string * _message, 
                                     int * _frameElapsed)
{
  this->calibration->executeCalibration(_mode, _view, _frameElapsed);
  //Notify all the observers
  this->updateObserver();
  return true;
}

bool SacaiLoader :: resetPoint()
{
  this->calibration->resetPoint();
  return true;
}

