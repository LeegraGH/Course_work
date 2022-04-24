#ifndef __CLASS4_H__
#define __CLASS4_H__
#include "other.h"
class Class4 : public Other
{
public:
	Class4(string name, Base* parent) : Other(name, parent) {};
};
#endif