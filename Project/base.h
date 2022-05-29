#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f) // для получения указателя на метод сигнала объекта
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f) // для получения указателя на метод обработчика объекта

class Base;
typedef void (Base::* TYPE_SIGNAL)(string&);
typedef void (Base::* TYPE_HANDLER)(string);

class Base
{
private:
	string name; // наименование объекта
	Base* parent; // указатель на головной объект для текущего объекта
	bool status = 0; // готовность объекта
	Base* current_obj = this; // указатель на текущий объект
	int num; // номер класса объекта
	vector <Base*> children; // вектор указателей на объекты, подчиненные к текущему объекту
	struct Connect // структура задания одной связи
	{
		TYPE_SIGNAL signal; // указатель на метод сигнала
		Base* target_obj; // указатель на целевой объект
		TYPE_HANDLER handler; // указатель на метод обработчика
	};
	vector <Connect*> connects; // вектор для хранения установленных связей
public:
	Base(Base* parent, string name = "", int num = 1); // указатель на головной объект в дереве иерархии и наименование объекта(имеет значение по умолчанию)
	~Base();
	void set_name(string name); // метод определения имени объекта
	string get_name(); // метод получения имени объекта
	void print(string spaces); // метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз
	void set_parent(Base* new_parent); // метод переопределения головного объекта для текущего в дереве иерархии
	Base* get_parent(); // метод получения указателя на головной объект текущего объекта
	Base* get_obj_by_name(string name_obj); // метод получения указателя на объект по имени
	void set_status(int status); // метод установки готовности объекта
	void print_readiness(string spaces); // вывод дерева иерархии объектов и их готовности
	void set_current(Base* obj); // метод установки указателя на текущий объект
	Base* get_current(); // метод получения указателя на текущий объект
	Base* get_obj_by_coordinate(string coordinate); // метод получения указателя на объект по координате

	void set_status_for_all();
	void set_connect(TYPE_SIGNAL signal, Base* target_obj, TYPE_HANDLER handler); // установка связи между сигналом текущего объекта и обработчиком целевого объекта
	void delete_connect(TYPE_SIGNAL signal, Base* target_obj, TYPE_HANDLER handler); // удаление связи между сигналом текущего объекта и обработчиком целевого объекта
	void emit_signal(TYPE_SIGNAL signal, string& command); // выдача сигнала от текущего объекта с передачей строковой переменной
	string absolute_path();
	int get_num();
	TYPE_SIGNAL	get_signal();
	TYPE_HANDLER get_handler();
};
#endif