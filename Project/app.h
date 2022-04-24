#ifndef __APP_H__
#define __APP_H__
#include "base.h"
#include "other.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include "class5.h"
#include "class6.h"
// класс приложение для создания корневого объекта дерева иерархии
class App : public Base
{
public:
	App(Base* parent) : Base(parent) {};
	void build_tree_obj(); // метод построения исходного дерева иерархии объектов
	int execute_app(); // метод запуска приложения
};
#endif