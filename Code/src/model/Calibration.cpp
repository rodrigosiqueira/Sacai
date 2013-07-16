/**
 * @file Calibration.cpp
 * @brief Implementation of calibration functions.
 **/
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <dataType.hpp>
#include <Setting.hpp>
#include <Calibration.hpp>
#include <InputPattern.hpp>
#include <ChessBoard.hpp>

using namespace std;

//namespace model
//{
	Calibration :: Calibration(string _pathConfigFile) : settings(Setting::getInstance())
	{
		this->previousTimeStamp = 0;
		this->settings.loadCalibrationFile(_pathConfigFile);
		this->setInputPatter();
	}

	Calibration :: ~Calibration()
	{
		delete this->recognitionPattern;
	}

	inline bool Calibration :: runCalibrationAndSave()
	{
		vector<cv::Mat> rotationVector, translationVector;
		vector<float> reprojectionError;
		double totalAverageError = 0;
		bool rc = false;
		string message = ". avg reprojection error = ";

		rc = this->runCalibration(
					rotationVector,
					translationVector,
					reprojectionError,
					totalAverageError);

		message += totalAverageError;
		if(rc)
		{
			cout << "Calibration succeeded" << message << endl;
			this->saveCameraParams(
					rotationVector,
					translationVector,
					reprojectionError,
					this->imagePoints,
					totalAverageError);
		}
		else
		{
			cout << "Calibration failed" << message << endl;
		}

		return rc;
	}

	bool Calibration :: executeCalibration(int _mode, cv::Mat * _view, string * _message)
	{
		bool found, blinkOutput = false;
		int baseLine = 0;
		cv::Size textSize;

		//Conditions for stop calibration
		if(this->mode == util::CAPTURING &&
			this->imagePoints.size() >= (unsigned)this->settings.numFrameForCalibration)
		{
			if(this->runCalibrationAndSave())
			{
				this->mode = util::CALIBRATED;
			}
			else
			{
				this->mode = util::DETECTION;
			}
		}
		//Verify if no more images
		if(this->view->empty())
		{
			if(this->imagePoints.size() > 0)
			{
				this->runCalibrationAndSave();
			}
			return false;
		}
		this->imageSize = this->view->size();
		if(this->settings.flipAroundHorizonAxis)
		{
			cv::flip(*(this->view), *(this->view), 0);
		}

		vector<cv::Point2f> detectedGeometry;
		found = this->recognitionPattern->findGeometry(
					*(this->view),
					detectedGeometry,
					this->settings.boardSize);
		//Draw the chessboard
		if(found)
		{
			if(this->mode == util::CAPTURING &&
				(!this->settings.inputCapture.isOpened() ||
				clock() - this->previousTimeStamp >
				this->settings.delayForVideoInput * 1e-3*CLOCKS_PER_SEC))
			{
				this->imagePoints.push_back(detectedGeometry);
				this->previousTimeStamp = clock();
				blinkOutput = this->settings.inputCapture.isOpened();
			}
			cv::drawChessboardCorners(*(this->view), this->settings.boardSize, cv::Mat(detectedGeometry), found);
		}
		//Output text
		*(this->message) = (this->mode == util::CAPTURING) ? "100/100" : this->mode == util::CALIBRATED ? "Calibrated" : "Press 'g' to start";

		textSize = cv::getTextSize(*(this->message), 1, 1, 1, &baseLine);
		cv::Point textOrigin(this->view->cols - 2*textSize.width - 10, this->view->rows - 2*baseLine - 10);

		if(this->mode == util::CAPTURING)
		{
			if(this->settings.showUndistorsed)
			{
				*(this->message) = cv::format( "%d/%d Undist", (int)this->imagePoints.size(), this->settings.numFrameForCalibration);
			}
			else
			{
				*(this->message) = cv::format( "%d/%d", (int)this->imagePoints.size(), this->settings.numFrameForCalibration);
			}
		}

		if(blinkOutput)
		{
			cv::bitwise_not(*(this->view), *(this->view));
		}

		//Video capture  output  undistorted
		if(this->mode == util::CALIBRATED && this->settings.showUndistorsed)
		{
			cv::Mat temp = this->view->clone();
			cv::undistort(temp, *(this->view), this->cameraMatrix, this->distortionCoefficients);
		}

		return true;
	}

	void Calibration :: resetPoint()
	{
		this->imagePoints.clear();
	}

	inline double Calibration :: computeReprojectionErrors(
					const vector<vector<cv::Point3f> >& _objectPoint,
					const vector<vector<cv::Point2f> >& _imagePoint,
					const vector<cv::Mat>& _rotationVector,
					const vector<cv::Mat>& _translationVector,
					vector<float>& _perViewErrors)
	{
		vector<cv::Point2f> imagePoints2;
		int i = 0, totalPoints = 0, numPoint = 0;
		double totalError = 0, partialError = 0;
		_perViewErrors.resize(_objectPoint.size());

		for(i = 0; i < (int)_objectPoint.size(); ++i)
		{
			cv::projectPoints(
				cv::Mat(_objectPoint[i]),
				_rotationVector[i],
				_translationVector[i],
				this->cameraMatrix,
				this->distortionCoefficients,
				imagePoints2);
			partialError = cv::norm(cv::Mat(_imagePoint[i]), cv::Mat(imagePoints2), CV_L2);

			numPoint = (int)_objectPoint[i].size();
			_perViewErrors[i] = (float) std::sqrt(partialError * partialError / numPoint);
			totalError += partialError * partialError;
			totalPoints += numPoint;
		}

		return std::sqrt(totalError/totalPoints);
	}

	inline void Calibration :: calcBoardCornerPositions(vector<cv::Point3f>& _corners)
	{
		register int i = 0, j = 0;
		float xCoordinate = 0.0, yCoordinate = 0.0;
		_corners.clear();

		switch(this->settings.calibrationPattern)
		{
			case util::CHESSBOARD:
			case util::CIRCLES_GRID:
				for(i = 0; i < this->settings.boardSize.height; ++i)
				{
					for(j = 0; j < this->settings.boardSize.width; ++j)
					{
						xCoordinate = j * this->settings.squareSize;
						yCoordinate = i * this->settings.squareSize;
						_corners.push_back(cv::Point3f(xCoordinate, yCoordinate, 0));
					}
				}
				break;

			case util::ASYMMETRIC_CIRCLES_GRID:
				for(i = 0; i < this->settings.boardSize.height; i++ )
				{
					for(j = 0; j < this->settings.boardSize.width; j++ )
					{
						xCoordinate = (2 * j + i % 2) * this->settings.squareSize;
						yCoordinate = i * this->settings.squareSize;
						_corners.push_back(cv::Point3f(xCoordinate, yCoordinate, 0));
					}
				}
				break;

			default:
				break;
		}
	}

	inline bool Calibration :: runCalibration(
				vector<cv::Mat>& _rotationVector,
				vector<cv::Mat>& _translationVector,
				vector<float>& _reprojErrs,
				double& _totalAvgErr)
	{
		double reprojCalibError = 0.0;
		bool checkCameraMatrix = false, checkDistortionMatrix = false;
		this->cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
		
		if(this->settings.flag && CV_CALIB_FIX_ASPECT_RATIO)
		{
			//Set 1.0 for the first element of camera matrix.
			this->cameraMatrix.at<double>(0,0) = 1.0;
		}

		this->distortionCoefficients = cv::Mat::zeros(8, 1, CV_64F);

		vector<vector<cv::Point3f> > objectPoints(1);
		this->calcBoardCornerPositions(objectPoints[0]);

		objectPoints.resize(this->imagePoints.size(), objectPoints[0]);

		//Find intrinsic and extrinsic camera parameters
		reprojCalibError = cv::calibrateCamera(
					objectPoints,
					this->imagePoints,
					this->imageSize,
					this->cameraMatrix,
					this->distortionCoefficients,
					_rotationVector,
					_translationVector,
					this->settings.flag | CV_CALIB_FIX_K4 | CV_CALIB_FIX_K5);

		cout << "Re-projection error reported by calibrateCamera: "<< reprojCalibError << endl;

		//Check every element of cameraMatrix input array for invalid values
		checkCameraMatrix = cv::checkRange(this->cameraMatrix);
		checkDistortionMatrix = cv::checkRange(this->distortionCoefficients);

		_totalAvgErr = this->computeReprojectionErrors(
						objectPoints,
						this->imagePoints,
						_rotationVector,
						_translationVector,
						_reprojErrs);

		return (checkCameraMatrix && checkDistortionMatrix);
	}

	inline void Calibration :: saveCameraParams(
				const vector<cv::Mat>& _rotationVector,
				const vector<cv::Mat>& _translationVector,
				const vector<float>& _reprojErrs,
				const vector<vector<cv::Point2f> >& _imagePoints,
				double _totalAvgErr)
	{
		cv::FileStorage fs(this->settings.outputFileName, cv::FileStorage::WRITE );

		time_t tm;
		time(&tm);
		struct tm *t2 = localtime(&tm);
		char buf[1024];
		strftime( buf, sizeof(buf)-1, "%c", t2 );

		fs << "calibration_Time" << buf;

		if(!_rotationVector.empty() || !_reprojErrs.empty())
		{
			fs << "nrOfFrames" << (int)std::max(_rotationVector.size(), _reprojErrs.size());
		}

		fs << "image_Width" << this->imageSize.width;
		fs << "image_Height" << this->imageSize.height;
		fs << "board_Width" << this->settings.boardSize.width;
		fs << "board_Height" << this->settings.boardSize.height;
		fs << "square_Size" << this->settings.squareSize;

		if(this->settings.flag & CV_CALIB_FIX_ASPECT_RATIO )
		{
			fs << "FixAspectRatio" << this->settings.aspectRatio;
		}

		if(this->settings.flag)
		{
			sprintf( buf, "flags: %s%s%s%s",
				this->settings.flag & CV_CALIB_USE_INTRINSIC_GUESS ? " +use_intrinsic_guess" : "",
				this->settings.flag & CV_CALIB_FIX_ASPECT_RATIO ? " +fix_aspectRatio" : "",
				this->settings.flag & CV_CALIB_FIX_PRINCIPAL_POINT ? " +fix_principal_point" : "",
				this->settings.flag & CV_CALIB_ZERO_TANGENT_DIST ? " +zero_tangent_dist" : "" );
			cvWriteComment(*fs, buf, 0);
		}

		fs << "flagValue" << this->settings.flag;

		fs << "Camera_Matrix" << this->cameraMatrix;
		fs << "Distortion_Coefficients" << this->distortionCoefficients;

		fs << "Avg_Reprojection_Error" << _totalAvgErr;
		if(!_reprojErrs.empty())
		{
			fs << "Per_View_Reprojection_Errors" << cv::Mat(_reprojErrs);
		}

		if(!_rotationVector.empty() && !_translationVector.empty())
		{
			CV_Assert(_rotationVector[0].type() == _translationVector[0].type());
			cv::Mat bigmat((int)_rotationVector.size(), 6, _rotationVector[0].type());
			for(int i = 0; i < (int)_rotationVector.size(); i++)
			{
				cv::Mat r = bigmat(cv::Range(i, i+1), cv::Range(0,3));
				cv::Mat t = bigmat(cv::Range(i, i+1), cv::Range(3,6));

				CV_Assert(_rotationVector[i].rows == 3 && _rotationVector[i].cols == 1);
				CV_Assert(_translationVector[i].rows == 3 && _translationVector[i].cols == 1);
				//*.t() is MatExpr (not Mat) so we can use assignment operator
				r = _rotationVector[i].t();
				t = _translationVector[i].t();
			}
			cvWriteComment( *fs, "a set of 6-tuples (rotation vector + translation vector) for each view", 0 );
			fs << "Extrinsic_Parameters" << bigmat;
		}

		if(!this->imagePoints.empty())
		{
			cv::Mat imagePtMat((int)this->imagePoints.size(), (int)this->imagePoints[0].size(), CV_32FC2);
			for(int i = 0; i < (int)this->imagePoints.size(); i++)
			{
				cv::Mat r = imagePtMat.row(i).reshape(2, imagePtMat.cols);
				cv::Mat imgpti(imagePoints[i]);
				imgpti.copyTo(r);
			}
			fs << "Image_points" << imagePtMat;
		}
	}

	inline bool Calibration :: setInputPatter()
	{
		switch(this->settings.calibrationPattern)
		{
			case util::CHESSBOARD:
				this->recognitionPattern = new ChessBoard();

			case util::CIRCLES_GRID:
				break;

			case util::ASYMMETRIC_CIRCLES_GRID:
					break;

			default:
				return false;
		}
		return true;
	}

	int Calibration :: stopCalibration()
	{
		return -1;
	}
//}
