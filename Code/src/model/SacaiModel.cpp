/**
 * @file SacaiModel.cpp
 **/
#include <opencv2/core/core.hpp>

#include <Calibration.hpp>
#include <SacaiModel.hpp>

//namespace model
//{
	SacaiModel :: SacaiModel()
	{
		this->calibration = new Calibration();
	}

	SacaiModel :: ~SacaiModel()
	{
		delete this->calibration;
	}

	bool SacaiModel :: startCalibration(int _mode, cv::Mat * _view, int _frameElapsed)
	{
		bool rc = false;

		this->modeCalibration = _mode;
		this->frameCalibration = _view;
		
		//Execute calibration
		this->frameElapsedCalibration = _frameElapsed;
		rc = this->calibration->executeCalibration(
				&(this->modeCalibration),
				this->frameCalibration,
				&(this->frameElapsedCalibration));
		//Notify all the observers
		this->updateObserver();

		return rc;
	}

	bool SacaiModel :: resetPoint()
	{
		this->calibration->resetPoint();
		return true;
	}
//}
