/**
 * @file SacaiController.cpp
 **/

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
//}
