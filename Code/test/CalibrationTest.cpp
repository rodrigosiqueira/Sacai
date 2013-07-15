#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "CalibrationTest.hpp"
#include "../inc/Calibration.hpp"
//#include "../inc/Setting.hpp"

using namespace cv;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(CalibrationTest);

//Configure the basic inicialization
void CalibrationTest :: setUp(void)
{
	this->calibration = new Calibration();
}

//Clean the memory when the test ends
void CalibrationTest :: tearDown(void)
{
	delete this->calibration;
}

//Teste load file
/*
void CalibrationTest :: loadCalibrationFileTest(void)
{
	//bool openFile = this->calibration->loadCalibrationFile();
	CPPUNIT_ASSERT_EQUAL(true, this->calibration->settings.goodInput);
}
*/
