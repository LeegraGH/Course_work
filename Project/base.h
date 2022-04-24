#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Base
{
private:
	string name; // наименование объекта
	Base* parent; // указатель на головной объект для текущего объекта
	// для корневого объекта значение указателя равно 0
	bool status = 0;
	vector <Base*> children; // массив указателей на объекты, подчиненные к текущему объекту
public:
	Base(Base* parent, string name = ""); // указатель на головной объект в дереве иерархии и наименование объекта(имеет значение по умолчанию)
		~Base();
	void set_name(string name); // метод определения имени объекта
	string get_name(); // метод получения имени объекта
	void print(string spaces); // метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз
		void set_parent(Base* new_parent); // метод переопределения головного объекта для текущего в дереве иерархии
		Base* get_parent(); // метод получения указателя на головной объект текущего объекта
		Base* get_obj_by_name(string name_obj); // метод получения указателя на объект по имени
		void set_status(int status); // метод установки готовности объекта
	void print_readiness(string spaces); // вывод дерева иерархии объектов и их готовности
};
#endif