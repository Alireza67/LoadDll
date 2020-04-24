#pragma once
class TunerInterface
{
public:
	virtual void setFreq(void) = 0;
	virtual void destroy(void) = 0;
};