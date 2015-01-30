/**
 * @file SacaiModel.cpp
 **/
#include <opencv2/core/core.hpp>

#include "Calibration.hpp"
#include "SacaiModel.hpp"

SacaiModel :: SacaiModel()
{
  this->calibration = new Calibration();
  this->recognizeCircle = new RecognizeCircle();
}

SacaiModel :: ~SacaiModel()
{
  delete this->calibration;
  delete this->recognizeCircle;
}

bool SacaiModel :: startCalibration(cv::Mat * _view)
{
  bool rc = false;

  if(!_view)
  {
    return false;
  }

  this->frameUpdate = _view;
  //Execute calibration
  rc = this->calibration->executeCalibration(NULL, _view, NULL);

  //Notify all the observers
  this->updateObserver();

  return rc;
}

bool SacaiModel :: resetPoint()
{
  this->calibration->resetPoint();
  return true;
}

bool SacaiModel :: startFindCircle(cv::Mat * _view)
{
  bool rc = false;

  this->frameUpdate = _view;

  rc = this->recognizeCircle->findCenter(this->frameUpdate);
  //Notify all the observers
  this->updateObserver();

  return rc;
}
