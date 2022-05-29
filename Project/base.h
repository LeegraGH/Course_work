#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f) // ��� ��������� ��������� �� ����� ������� �������
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f) // ��� ��������� ��������� �� ����� ����������� �������

class Base;
typedef void (Base::* TYPE_SIGNAL)(string&);
typedef void (Base::* TYPE_HANDLER)(string);

class Base
{
private:
	string name; // ������������ �������
	Base* parent; // ��������� �� �������� ������ ��� �������� �������
	bool status = 0; // ���������� �������
	Base* current_obj = this; // ��������� �� ������� ������
	int num; // ����� ������ �������
	vector <Base*> children; // ������ ���������� �� �������, ����������� � �������� �������
	struct Connect // ��������� ������� ����� �����
	{
		TYPE_SIGNAL signal; // ��������� �� ����� �������
		Base* target_obj; // ��������� �� ������� ������
		TYPE_HANDLER handler; // ��������� �� ����� �����������
	};
	vector <Connect*> connects; // ������ ��� �������� ������������� ������
public:
	Base(Base* parent, string name = "", int num = 1); // ��������� �� �������� ������ � ������ �������� � ������������ �������(����� �������� �� ���������)
	~Base();
	void set_name(string name); // ����� ����������� ����� �������
	string get_name(); // ����� ��������� ����� �������
	void print(string spaces); // ����� ������ ������������ �������� � ������ �������� ����� ������� � ������ ����
	void set_parent(Base* new_parent); // ����� ��������������� ��������� ������� ��� �������� � ������ ��������
	Base* get_parent(); // ����� ��������� ��������� �� �������� ������ �������� �������
	Base* get_obj_by_name(string name_obj); // ����� ��������� ��������� �� ������ �� �����
	void set_status(int status); // ����� ��������� ���������� �������
	void print_readiness(string spaces); // ����� ������ �������� �������� � �� ����������
	void set_current(Base* obj); // ����� ��������� ��������� �� ������� ������
	Base* get_current(); // ����� ��������� ��������� �� ������� ������
	Base* get_obj_by_coordinate(string coordinate); // ����� ��������� ��������� �� ������ �� ����������

	void set_status_for_all();
	void set_connect(TYPE_SIGNAL signal, Base* target_obj, TYPE_HANDLER handler); // ��������� ����� ����� �������� �������� ������� � ������������ �������� �������
	void delete_connect(TYPE_SIGNAL signal, Base* target_obj, TYPE_HANDLER handler); // �������� ����� ����� �������� �������� ������� � ������������ �������� �������
	void emit_signal(TYPE_SIGNAL signal, string& command); // ������ ������� �� �������� ������� � ��������� ��������� ����������
	string absolute_path();
	int get_num();
	TYPE_SIGNAL	get_signal();
	TYPE_HANDLER get_handler();
};
#endif