#pragma once

#include "base.h"
#include "other.h"

// класс приложение для создания корневого объекта дерева иерархии

class App : public Base
{
public:
	App(Base* parent, int num) : Base(parent, num) {};
	void build_tree_obj(); // метод построения исходного дерева иерархии объектов
	int execute_app(); // метод запуска приложения
};