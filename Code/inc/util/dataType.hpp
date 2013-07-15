/**
 * @file dataType.hpp
 * @brief Data definitions
 **/
#ifndef _DATA_TYPE_HPP_
#define _DATA_TYPE_HPP_

#include <string>

namespace util
{
	/**
	 * @enum Pattern
	 * @brief Just define some default values for camera calibration.
	 **/
	enum Pattern
	{
		NOT_EXISTING,
		CHESSBOARD,
		CIRCLES_GRID,
		ASYMMETRIC_CIRCLES_GRID
	};

	/**
	 * @enum InputType
	 * @brief Define the type of input for processing.
	 **/
	enum InputType
	{
		INVALID,
		CAMERA,
		VIDEO_FILE,
		IMAGE_LIST
	};

	/**
	 * @enum StatusCalibration
	 * @brief Definition of some status of calibration.
	 **/
	enum StatusCalibration
	{
		DETECTION = 0,
		CAPTURING = 1,
		CALIBRATED = 2
	};

	/**
	 * @enum CommandList
	 * @brief Command code actions.
	 **/
	enum CommandList
	{
		CALIBRATION_COMMAND = 0
	};

	enum KeyBoard
	{
		ESC_KEY = 27
	};

	const std::string CONFIG_CALIB_DEFAULT = "default.yaml";
};

#endif
