#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "SettingTest.hpp"
#include "../inc/Setting.hpp"

using namespace cv;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(SettingTest);

//Configure the basic inicialization
void SettingTest :: setUp(void)
{
}

//Clean the memory when the test ends
void SettingTest :: tearDown(void)
{
}

static void read(const FileNode& node, Setting& x, const Setting& default_value = Setting())
{
	if(node.empty())
	{
		x = default_value;
	}
	else
	{
		x.read(node);
	}
}

//Test the Read
void SettingTest :: readSettingTest(void)
{
	Setting settingTest;
	FileStorage fileStorage("default.yaml", FileStorage::READ);
	CPPUNIT_ASSERT_EQUAL(true, fileStorage.isOpened());
	//The rest of verification is based of file.
	fileStorage["Settings"] >> settingTest;
	fileStorage.release();
	CPPUNIT_ASSERT_EQUAL(false, fileStorage.isOpened());
	//File
	CPPUNIT_ASSERT_EQUAL(true, settingTest.goodInput);
	CPPUNIT_ASSERT_EQUAL(jvr::CAMERA, settingTest.inputType);
	CPPUNIT_ASSERT_EQUAL(6, settingTest.boardSize.width);
	CPPUNIT_ASSERT_EQUAL(9, settingTest.boardSize.height);
	CPPUNIT_ASSERT_EQUAL(0, settingTest.cameraId);
	CPPUNIT_ASSERT_EQUAL(100, settingTest.delayForVideoInput);
	CPPUNIT_ASSERT_EQUAL(true, settingTest.showUndistorsed);
}

void SettingTest :: writeSettingTest(void)
{

}

void SettingTest :: nextImageTest(void)
{

}

