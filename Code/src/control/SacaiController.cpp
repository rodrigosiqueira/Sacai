/**
 * @file SacaiController.cpp
 **/
#include <opencv2/core/core.hpp>

#include <SacaiController.hpp>
#include <SacaiLoader.hpp>
#include <CameraView.hpp>

//using namespace view;
//using namespace model;

//namespace control
//{
	SacaiController :: SacaiController(SacaiLoader * _model)
	{
		this->modelSacai = _model;
		this->viewSacai = new CameraView(this, _model);
	}

	SacaiController :: ~SacaiController()
	{
		delete this->viewSacai;
	}

	bool SacaiController :: showWindow(bool _show)
	{
		if(_show)
		{
			this->viewSacai->display();
			return true;
		}
		else
		{
			return _show;
		}
	}

	bool SacaiController :: callResetPoint()
	{
		this->modelSacai->resetPoint();
		return true;
	}

	bool SacaiController :: callCalibration(
				int * _mode, cv::Mat * _view, std::string * _message, int * _frameElapsed)
	{
		this->modelSacai->startCalibration(_mode, _view, _message, _frameElapsed);
		return true;
	}
//}
