/**
 * @file Calibration.hpp
 * @brief Class responsable for doing calibration and save the result.
 **/

#ifndef _CALIBRATION_HPP_
#define _CALIBRATION_HPP_

#include <iostream>
#include <opencv2/core/core.hpp>

#include <Setting.hpp>
#include <InputPattern.hpp>
#include <dataType.hpp>

//namespace model
//{
	/**
	 * @class Calibration
	 * @brief Keeps the attribute and methods for doing calibration.
	 **/
	class Calibration
	{
		public:
			Setting& settings;
			InputPattern * recognitionPattern;
			vector<vector<cv::Point2f> > imagePoints;
			cv::Size imageSize;
			clock_t previousTimeStamp;
			cv::Mat cameraMatrix;
			cv::Mat distortionCoefficients;

			Calibration(string _pathConfigFile = util::CONFIG_CALIB_DEFAULT);
			virtual ~Calibration();
			bool executeCalibration(int * _mode, cv::Mat * _view, int * _frameElapsed);
			void resetPoint();

		protected:
			/**
			 * @param _objectPoint
			 * @param _imagePoints
			 * @param _rotationVector
			 * @param _translationVector
			 * @param _perViewErrors
			 * @return
			 * @brief Find the average error of calibration operation.
			 **/
			double computeReprojectionErrors(
					const vector<vector<cv::Point3f> >& _objectPoint,
					const vector<vector<cv::Point2f> >& _imagePoints,
					const vector<cv::Mat>& _rotationVector,
					const vector<cv::Mat>& _translationVector,
					vector<float>& _perViewErrors);
					
			/**
			 * @param[out] _corners Fill with points.
			 * @brief This method gives some supports the use of
			 * calibrateCamera and calculates how should the pattern look.
			 **/
			void calcBoardCornerPositions(vector<cv::Point3f>& _corners);

			/**
			 * @param _rotationVector Matrix with rotation parameters.
			 * @param _translationVector Matrix with translation parameters.
			 * @param _reprojErrs Receive reprojection error.
			 * @param _totalAvgErr Average of error.
			 * @return If the range of matrix all right, return true.
			 * @brief Run calibration and fill the parameters.
			 **/
			bool runCalibration(
					vector<cv::Mat>& _rotationVector,
					vector<cv::Mat>& _translationVector,
					vector<float>& _reprojErrs,
					double& _totalAvgErr);

			/**
			 * @param _rotationVector
			 * @param
			 * @param
			 * @param
			 * @return
			 * @brief
			 **/
			void saveCameraParams(
				const vector<cv::Mat>& _rotationVector,
				const vector<cv::Mat>& _translationVector,
				const vector<float>& _reprojErrs,
				const vector<vector<cv::Point2f> >& _imagePoints,
				double _totalAvgErr);

			/**
			 * @return
			 * @brief
			 **/
			bool runCalibrationAndSave();

			/**
			 * @return
			 * @brief
			 **/
			virtual bool setInputPatter();
	};
//};
#endif
