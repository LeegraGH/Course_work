#pragma once

#include "base.h"

// ����� ��� �������� ��������� �������� ������

class Other : public Base
{
public:
	Other(string name, Base* parent, int num) : Base(parent, num, name) {};
};
