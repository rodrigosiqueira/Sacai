/**
 * @file SacaiLoader.hpp
 **/

#ifndef _SACAI_LOADER_HPP_
#define _SACAI_LOADER_HPP_

#include <ModelInterface.hpp>
#include <Calibration.hpp>

//namespace model
//{
	/**
	 * @class SacaiLoader
	 * @brief This class encapsulate the many actions in commands.
	 **/
	class SacaiLoader : public ModelInterface
	{
		public:
			SacaiLoader();
			virtual ~SacaiLoader();

		private:
			Calibration * calibration;
	};
//};

#endif
