#ifndef __OTHER_H__
#define __OTHER_H__

#include "base.h"

// класс для создания остальных объектов дерева

class Other : public Base
{
public:
	Other(string name, Base* parent, int num) : Base(parent, name, num) {};
};

#endif