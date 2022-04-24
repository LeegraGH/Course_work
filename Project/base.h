#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Base
{
private:
	string name; // ������������ �������
	Base* parent; // ��������� �� �������� ������ ��� �������� �������
	// ��� ��������� ������� �������� ��������� ����� 0
	bool status = 0;
	vector <Base*> children; // ������ ���������� �� �������, ����������� � �������� �������
public:
	Base(Base* parent, string name = ""); // ��������� �� �������� ������ � ������ �������� � ������������ �������(����� �������� �� ���������)
		~Base();
	void set_name(string name); // ����� ����������� ����� �������
	string get_name(); // ����� ��������� ����� �������
	void print(string spaces); // ����� ������ ������������ �������� � ������ �������� ����� ������� � ������ ����
		void set_parent(Base* new_parent); // ����� ��������������� ��������� ������� ��� �������� � ������ ��������
		Base* get_parent(); // ����� ��������� ��������� �� �������� ������ �������� �������
		Base* get_obj_by_name(string name_obj); // ����� ��������� ��������� �� ������ �� �����
		void set_status(int status); // ����� ��������� ���������� �������
	void print_readiness(string spaces); // ����� ������ �������� �������� � �� ����������
};
#endif