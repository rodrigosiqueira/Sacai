/**
 * @file CameraView.hpp
 **/
#ifndef _CAMERA_VIEW_HPP_
#define _CAMERA_VIEW_HPP_

#include <iostream>

#include <opencv2/core/core.hpp>

#include "ViewInterface.hpp"
#include "ControllerInterface.hpp"
#include "ModelInterface.hpp"
#include "Setting.hpp"

/**
 * @class CameraView
 * @brief Concrete class that handles camera visualization. This
 * class is observer for the model.
 **/
class CameraView : public ViewInterface
{
  public:
    /**
    * @param _control Reference for control class. This parameter is
    * used for doing interface action.
    * @param _model Reference for model. This keeps interface updated.
    * @brief This construct receives the maily elements for doing interface
    * operation.
    **/
    CameraView(ControllerInterface * _control, ModelInterface * _model);

    virtual ~CameraView();

    /**
    * @see ViewInterface
    **/
    virtual bool display();
    virtual void update(cv::Mat& _view);

    virtual cv::Mat * getFrame()
    {
      return &(this->frameView);
    }

  private:
    std::string nameWindow;
    std::string message;
    cv::Mat frameView;
    Setting& settings;
};

#endif
