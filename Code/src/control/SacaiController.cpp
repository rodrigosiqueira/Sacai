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
		this->viewSacai->display();
	}

	SacaiController :: ~SacaiController()
	{
		delete this->viewSacai;
	}

	bool SacaiController :: callCalibration(int _mode, cv::Mat * _view, std::string * _message)
	{
		this->modelSacai->calibration->executeCalibration(_mode, _view, _message);
		return true;
	}
//}
