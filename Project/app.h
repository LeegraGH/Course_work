#pragma once

#include "base.h"
#include "other.h"

// ����� ���������� ��� �������� ��������� ������� ������ ��������

class App : public Base
{
public:
	App(Base* parent, int num) : Base(parent, num) {};
	void build_tree_obj(); // ����� ���������� ��������� ������ �������� ��������
	int execute_app(); // ����� ������� ����������
};