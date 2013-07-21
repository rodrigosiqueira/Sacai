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

#include <SacaiModel.hpp>
#include <SacaiController.hpp>

using namespace cv;
using namespace std;

//int argc, char* argv[]
int main()
{
	SacaiModel * _model = new SacaiModel();
	SacaiController * _control = new SacaiController(_model);
	_control->showWindow(true);
	return 0;
}
