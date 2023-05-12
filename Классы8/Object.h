#pragma once
#include "TEvent.h"
class Object
{
public:
	Object(void);
	~Object(void);
	virtual void Show() = 0;
	virtual void Input() = 0;
};

