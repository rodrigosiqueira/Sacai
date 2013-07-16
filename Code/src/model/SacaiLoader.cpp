/**
 * @file SacaiLoader.cpp
 **/
#include <opencv2/core/core.hpp>

#include <Calibration.hpp>
#include <SacaiLoader.hpp>

//namespace model
//{
	SacaiLoader :: SacaiLoader()
	{
		this->calibration = new Calibration();
		this->calibrationDone = false;
	}

	SacaiLoader :: ~SacaiLoader()
	{
		delete this->calibration;
	}

	bool SacaiLoader :: startCalibration(int _mode, cv::Mat * _view, std::string * _message)
	{
		this->calibration->executeCalibration(_mode, _view, _message);
		//Notify all the observers
		this->updateObserver();
		return true;
	}
//}
