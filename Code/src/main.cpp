/**
 * @file main.cpp
 * @brief
 * @see http://docs.opencv.org/doc/tutorials/calib3d/camera_calibration/camera_calibration.html
 **/

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <JavariLoader.hpp>
#include <JavariController.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	JavariLoader * model = new JavariLoader();
	JavariController * control = new JavariController(model);
	return 0;
}
