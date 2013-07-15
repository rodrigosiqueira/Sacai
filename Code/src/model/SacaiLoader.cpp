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
	}

	SacaiLoader :: ~SacaiLoader()
	{
		delete this->calibration;
	}
//}
