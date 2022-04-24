#ifndef __CLASS6_H__
#define __CLASS6_H__
#include "other.h"
class Class6 : public Other
{
public:
	Class6(string name, Base* parent) : Other(name, parent) {};
};
#endif