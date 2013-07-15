/**
 * @file JavariController.cpp
 **/

#include <JavariController.hpp>
#include <ModelInterface.hpp>
#include <CameraView.hpp>

JavariController :: JavariController(JavariLoader * _model)
{
	this->model = _model;
	this->view = new CameraView(this, this->model);
	this->view->display();
}

JavariController :: ~JavariController()
{
	delete this->view;
}

bool JavariController :: startCalibration()
{
	this->model->startCalibration();
	return true;
}
