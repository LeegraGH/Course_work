#pragma once

#include "base.h"

// класс для создания остальных объектов дерева

class Other : public Base
{
public:
	Other(string name, Base* parent, int num) : Base(parent, num, name) {};
};
