#ifndef __APP_H__
#define __APP_H__
#include "base.h"
#include "other.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include "class5.h"
#include "class6.h"
// ����� ���������� ��� �������� ��������� ������� ������ ��������
class App : public Base
{
public:
	App(Base* parent) : Base(parent) {};
	void build_tree_obj(); // ����� ���������� ��������� ������ �������� ��������
	int execute_app(); // ����� ������� ����������
	void signal(string& text)
	{
		cout << "\nSignal from " << absolute_path();
		text += " (class: 1)";
	}
	void handler(string text)
	{
		cout << "\nSignal to " << absolute_path() << " Text: " << text;
	}
};
#endif