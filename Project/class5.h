#ifndef __CLASS5_H__
#define __CLASS5_H__
#include "other.h"
class Class5 : public Other
{
public:
	Class5(string name, Base* parent) : Other(name, parent) {};
};
#endif