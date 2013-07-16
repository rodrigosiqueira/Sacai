/**
 * @file ModelInterface.hpp
 **/
#include <iostream>

#include <ModelInterface.hpp>
//#include <ViewInterface.hpp>

using namespace std;

//namespace model
//{

	ModelInterface :: ModelInterface()
	{
	}

	ModelInterface :: ~ModelInterface()
	{

	}

	void ModelInterface :: registerObserver(ViewInterface * _observer)
	{
		this->listOfObserver.push_back(_observer);
	}

	void ModelInterface :: updateObserver()
	{
		vector<ViewInterface *>::iterator it;
		for (it = this->listOfObserver.begin() ; it != this->listOfObserver.end(); ++it)
		{
			(*it)->update(
				this->modeCalibration,
				(*this->frameCalibration),
				this->frameElapsedCalibration);
		}
	}
//};
