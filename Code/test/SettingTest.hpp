/**
 * @file SettingTest.hpp
 * @brief Unitary test for class Setting
 **/
#ifndef _SETTING_TEST_HPP_
#define _SETTING_TEST_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../inc/Setting.hpp"

using namespace std;

/**
 * @class KeyWordTest
 **/
class SettingTest : public CPPUNIT_NS :: TestFixture
{
	private:
		CPPUNIT_TEST_SUITE(SettingTest);
		CPPUNIT_TEST(readSettingTest);
		CPPUNIT_TEST(writeSettingTest);
		CPPUNIT_TEST(nextImageTest);
		CPPUNIT_TEST_SUITE_END();
		
	public:
		void setUp(void);
		void tearDown(void);
	
	protected:
		void readSettingTest(void);
		void writeSettingTest(void);
		void nextImageTest(void);
};

#endif

