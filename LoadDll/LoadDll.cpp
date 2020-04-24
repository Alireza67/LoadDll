#include "pch.h"
#include "FactoryClass.h"

int main()
{
	TunerInterface* myTuner = FactoryTuner::create("two");
	if (myTuner == nullptr)
		throw invalid_argument("Can not load Tuner!\n");
	myTuner->setFreq();

	myTuner->destroy();
	
	return 0;
}