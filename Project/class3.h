#ifndef __CLASS3_H__
#define __CLASS3_H__
#include "other.h"
class Class3 : public Other
{
public:
	Class3(string name, Base* parent) : Other(name, parent) {};
};
#endif