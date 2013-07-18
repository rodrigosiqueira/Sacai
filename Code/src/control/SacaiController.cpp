/**
 * @file SacaiController.cpp
 **/
#include <opencv2/core/core.hpp>

#include <SacaiController.hpp>
#include <SacaiModel.hpp>
#include <CameraView.hpp>

SacaiController :: SacaiController(SacaiModel * _model)
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

bool SacaiController :: callCalibration()
{
	bool rc = false;

	rc = this->modelSacai->startCalibration(
			this->viewSacai->getMode(),
			this->viewSacai->getFrame(),
			this->viewSacai->getFrameElapse());

	return rc;
}

bool SacaiController :: callFindCircle()
{
	bool rc = false;

	rc = this->modelSacai->startFindCircle(
			this->viewSacai->getMode(),
			this->viewSacai->getFrame(),
			this->viewSacai->getFrameElapse());

	return rc;
}
