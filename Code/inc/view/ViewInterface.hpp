/**
 * @file ViewInterface.hpp
 **/
#ifndef _VIEW_INTERFACE_HPP_
#define _VIEW_INTERFACE_HPP_

#include <string>

#include <opencv2/core/core.hpp>

#include <ModelInterface.hpp>
#include <ControllerInterface.hpp>

using namespace std;

class ModelInterface;
class ControllerInterface;

//namespace view
//{
	/**
	 * @class ViewInterface
	 * @brief Abstract class used in MVC which Subject. 
	 **/
	class ViewInterface
	{
		public:
			/**
			 * @brief Update image for specific situation.
			 **/
			virtual void update(string _message, cv::Mat _frame, cv::Size _textSize) = 0;
			/**
			 * @return If all right return true, otherwise false.
			 * @brief Implements specific visualization.
			 **/
			virtual bool display() = 0;

		protected:
			ModelInterface * modelView;
			ControllerInterface * controlView;

			ViewInterface(){}
			virtual ~ViewInterface(){}
	};
//};

#endif
