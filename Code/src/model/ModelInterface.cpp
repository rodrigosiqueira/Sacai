/**
 * @file ModelInterface.hpp
 **/
#include <iostream>

#include <ModelInterface.hpp>

ModelInterface :: ModelInterface()
{
	this->modeCalibration = 0;
	this->frameElapsedCalibration = 0;
}

ModelInterface :: ~ModelInterface()
{
	delete frameCalibration;
}

bool ModelInterface :: registerObserver(ViewInterface * _observer)
{
	if(_observer)
	{
		this->listOfObserver.push_back(_observer);
		return true;
	}
	else
	{
		return false;
	}
}

void ModelInterface :: updateObserver()
{
	std::vector<ViewInterface *>::iterator it;
	for(it = this->listOfObserver.begin(); it != this->listOfObserver.end(); ++it)
	{
		(*it)->update(
			this->modeCalibration,
			(*this->frameCalibration),
			this->frameElapsedCalibration);
	}

	return;
}
