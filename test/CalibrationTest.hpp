/**
 * @file CalibrationTest.hpp
 * @brief Unitary test for class Calibration
 **/
#ifndef _CALIBRATION_TEST_HPP_
#define _CALIBRATION_TEST_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../inc/Calibration.hpp"

using namespace std;
/**
 * @class CalibrationTest
 **/
class CalibrationTest : public CPPUNIT_NS :: TestFixture
{
	private:
		Calibration * calibration;
		CPPUNIT_TEST_SUITE(CalibrationTest);
		//CPPUNIT_TEST(loadCalibrationFileTest);
		CPPUNIT_TEST_SUITE_END();
	public:
		void setUp(void);
		void tearDown(void);

	protected:
		//void loadCalibrationFileTest(void);
		//void executeCalibrationTest(void);
};

#endif
