#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base
{
protected:
	string name; // ������������ �������
	Base* parent; // ��������� �� �������� ������ ��� �������� �������
	// ��� ��������� ������� �������� ��������� ����� 0
	int num; // ����� �������
	int status=0;
	vector <Base*> children; // ������ ���������� �� �������, ����������� � �������� �������
public:
	Base(Base* parent, int num, string name = ""); // ��������� �� �������� ������ � ������ �������� � ������������ �������(����� �������� �� ���������)
	~Base();
	void set_name(string name); // ����� ����������� ����� �������
	string get_name(); // ����� ��������� ����� �������
	void print(); // ����� ������ ������������ �������� � ������ �������� ����� ������� � ������ ����
	void set_parent(Base* new_parent); // ����� ��������������� ��������� ������� ��� �������� � ������ ��������
	Base* get_parent(); // ����� ��������� ��������� �� �������� ������ �������� �������
	Base* get_obj_by_name(string name_obj); // ����� ��������� ��������� �� ������ �� �����
	void set_status(int status); // ����� ��������� ���������� �������
	void print_readiness(); // ����� ������ �������� �������� � �� ����������
};