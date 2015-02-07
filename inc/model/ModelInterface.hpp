/**
 * @file ModelInterface.hpp
 * @brief Subject interface (Pattern Observer).
 **/
#ifndef _MODEL_INTERFACE_HPP_
#define _MODEL_INTERFACE_HPP_

#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>

#include "ViewInterface.hpp"

class ViewInterface;

/**
 * @class ModelInterface
 * @brief Interface for model with methods for pattern Observer. This
 * class represent the Subject in pattern observer.
 **/
class ModelInterface
{
  public:
    /**
    * @param _observer Observer to register.
    * @brief This method is a part of Observer Patter. Basically, It register
    * the observer of actions.
    **/
    bool registerObserver(ViewInterface * _observer);

    /**
    * @brief Update all observers.
    **/
    void updateObserver();

    /**
    * @param _view Target frame for calibration.
    * @return Return true if all right and false otherwise.
    * @brief Method that encapsulate the action of call calibration.
    **/
    virtual bool startCalibration(cv::Mat * _view) = 0;

    /**
    * @return Return true if all right, and false otherwise.
    * @brief Reset the vector of points.
    **/
    virtual bool resetPoint() = 0;

    /**
    * @param
    * @return
    * @brief
    **/
    virtual bool startFindCircle(cv::Mat * _view) = 0;

    virtual int getMode() = 0;
    virtual int getFrameElapse() = 0;
    virtual bool getCalibrationDone() = 0;
    virtual int getRadius() = 0;
    virtual cv::Point * getCenter() = 0;

  protected:
    std::vector<ViewInterface *> listOfObserver;
    cv::Mat * frameUpdate; /**< Used for updating observers in calibration.*/

    ModelInterface();
    virtual ~ModelInterface();
};

#endif
