/**
 * @file Setting.hpp
 * @brief Definition of class Setting. 
 **/

#ifndef _SETTING_HPP_
#define _SETTING_HPP_

#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <dataType.hpp>

using namespace std;

/**
 * @class Setting
 * @brief This class handle the input file with configuration, write one file with
 * settings, and make some configurations.
 **/
class Setting
{
	public:
		cv::Size boardSize;				/**< Number of inner corners per a item row and column.*/
		jvr::Pattern calibrationPattern; 	/**< Can be: Chessboard, circles, or asymmetric.*/
		float squareSize;			/**< The size of square in your defined unit.*/
		int numFrameForCalibration;	/**< The number of frames to use from the input for calibration. */
		float aspectRatio;
		int delayForVideoInput;
		bool writePoint;			/**< Write to the output file the feature points.*/
		bool writeExtrinsics;
		bool calibZeroTangDistortion;
		bool calibFixPrincipalPoint;
		bool flipAroundHorizonAxis;
		string outputFileName;
		bool showUndistorsed;
		string input;
		
		int cameraId;
		vector<string> imageList;
		int atImageList;
		cv::VideoCapture inputCapture;
		jvr::InputType inputType;
		bool goodInput;				/**< Just test if all right with input.*/
		int flag;

		//PENSAR EM UMA MANEIRA DE TORNAR ESTE CONSTRUTOR PRIVADO
		virtual ~Setting();

		static Setting& getInstance()
		{
			static Setting instance;
			return instance;
		}

		bool loadCalibrationFile(string _path);

		/**
		 * @param
		 * @brief
		 **/
		void write(cv::FileStorage& _fileStorage) const;

		/**
		 * @param
		 * @brief
		 **/
		void read(const cv::FileNode& _node);

		/**
		 * @return Return next frame.
		 * @brief Capture the next frame and return it.
		 **/
		cv::Mat nextImage();

	private:
		Setting();
		string patternToUse;

		/**
		 * @brief
		 **/
		void interpret();
};

#endif
