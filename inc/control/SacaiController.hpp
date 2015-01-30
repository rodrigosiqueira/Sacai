/**
 * @file SacaiController.hpp
 **/

#ifndef _SACAI_CONTROLLER_HPP_
#define _SACAI_CONTROLLER_HPP_

#include <opencv2/core/core.hpp>

#include "SacaiModel.hpp"
#include "ControllerInterface.hpp"
#include "CameraView.hpp"

/**
 * @class SacaiController
 * @brief The interface view calls the methods of the model class.
 * @see ControllerInterface
 **/
class SacaiController : public ControllerInterface
{
  public:
    /**
    * @param _model Reference for model layer.
    **/
    SacaiController(SacaiModel * _model);
    virtual ~SacaiController();

    /**
    *@see ControllerInterface
    **/
    virtual bool callCalibration();

    /**
    *@see ControllerInterface
    **/
    virtual bool callFindCircle();

    virtual bool showWindow(bool _show);
    virtual bool callResetPoint();

  private:
    CameraView * viewSacai;
};

#endif
