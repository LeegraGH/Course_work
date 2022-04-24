#ifndef __CLASS2_H__
#define __CLASS2_H__
#include "other.h"
class Class2 : public Other
{
public:
	Class2(string name, Base* parent) : Other(name, parent) {};
};
#endif