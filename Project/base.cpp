#include "base.h"
#include "app.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include "class5.h"
#include "class6.h"

Base::Base(Base* parent, string name, int num)
{
	this->name = name;
	this->parent = parent;
	this->num = num;
	if (parent != nullptr)
	{
		parent->children.push_back(this);
	}
}

Base::~Base()
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void Base::set_name(string name)
{
	this->name = name;
}

string Base::get_name()
{
	return name;
}

void Base::print(string spaces)
{
	if (children.size() != 0)
	{
		spaces += "    ";
		for (int i = 0; i < children.size(); i++)
		{
			cout << endl;
			cout << spaces << children[i]->get_name();
			children[i]->print(spaces);
		}
	}
}

void Base::set_parent(Base* new_parent)
{
	if (parent != nullptr)
	{
		for (int i = 0; i < parent->children.size(); i++)
		{
			if (parent->children[i] == (this))
			{
				parent->children.erase(parent->children.begin() + i);
			}
		}
		parent = new_parent;
	}
	if (parent != nullptr)
	{
		parent->children.push_back(this);
	}
}

Base* Base::get_parent()
{
	return parent;
}

Base* Base::get_obj_by_name(string name_obj)
{
	Base* parent_ptr;
	Base* obj_ptr = nullptr;
	if (this->get_name() == name_obj) return this;
	for (int i = 0; i < children.size(); i++)
	{
		parent_ptr = children[i];
		if (children[i]->get_name() == name_obj)
		{
			obj_ptr = children[i];
			return obj_ptr;
		}
		else
		{
			if (parent_ptr->children.size() != 0)
			{
				obj_ptr = parent_ptr->get_obj_by_name(name_obj);
			}
			if (obj_ptr != nullptr) return obj_ptr;
		}
	}
	return obj_ptr;
}

void Base::set_status(int status)
{
	Base* obj = this;
	if (status == 0)
	{
		this->status = 0;
		for (int i = 0; i < obj->children.size(); i++)
		{
			obj->children[i]->set_status(0);
		}
	}
	else
	{
		while (obj->parent != nullptr)
		{
			if (obj->parent->status == 0)
			{
				this->status = 0;
				return;
			}
			obj = obj->parent;
		}
		this->status = 1;
	}
}

void Base::print_readiness(string spaces)
{
	if (status == 0) cout << " is not ready";
	else cout << " is ready";
	if (children.size() != 0)
	{
		spaces += "    ";
		for (int i = 0; i < children.size(); i++)
		{
			cout << endl;
			cout << spaces << children[i]->get_name();
			children[i]->print_readiness(spaces);
		}
	}
}

void Base::set_current(Base* obj)
{
	current_obj = obj;
}

Base* Base::get_current()
{
	return current_obj;
}

Base* Base::get_obj_by_coordinate(string coordinate)
{
	if (coordinate == "") return nullptr;
	else if (coordinate == "/")
	{
		return this;
	}
	else if (coordinate.substr(0, 2) == "//")
	{
		return get_obj_by_name(coordinate.substr(2));
	}
	else if (coordinate == ".")
	{
		return current_obj;
	}
	else if (coordinate[0] == '/')
	{
		string nameObj;
		if (coordinate.find("/", 1) == string::npos)
		{
			nameObj = coordinate.substr(1);
			for (int i = 0; i < children.size(); i++)
			{
				if (children[i]->get_name() == nameObj) return children[i];
			}
			return nullptr;
		}
		else
		{
			nameObj = coordinate.substr(1, coordinate.find('/', 1) - 1);
			for (int i = 0; i < children.size(); i++)
			{
				if (children[i]->get_name() == nameObj)
					return children[i]->get_obj_by_coordinate(coordinate.substr(coordinate.find('/', 1)));
			}
			return nullptr;
		}
	}
	else return current_obj->get_obj_by_coordinate("/" + coordinate);
}

void Base::set_connect(TYPE_SIGNAL signal, Base* target_obj, TYPE_HANDLER handler)
{
	Connect* obj;
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->signal == signal && connects[i]->handler == handler && connects[i]->target_obj == target_obj)
		{
			return;
		}
	}
	obj = new Connect;
	obj->signal = signal;
	obj->handler = handler;
	obj->target_obj = target_obj;
	connects.push_back(obj);
}

void Base::delete_connect(TYPE_SIGNAL signal, Base* target_obj, TYPE_HANDLER handler)
{
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->signal == signal && connects[i]->handler == handler && connects[i]->target_obj == target_obj)
		{
			connects.erase(connects.begin() + i);
			break;
		}
	}
}

void Base::emit_signal(TYPE_SIGNAL signal, string& command)
{
	if (status == 0) return;
	(this->*signal)(command);
	for (int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->signal == signal)
		{
			if (connects[i]->target_obj->status != 0)
				((connects[i]->target_obj)->*(connects[i]->handler))(command);
		}
	}
}

string Base::absolute_path()
{
	if (parent == nullptr) return "/";
	string path = get_name();
	Base* parent_ptr = parent;
	while (parent_ptr->get_parent() != nullptr)
	{
		path = parent_ptr->get_name() + "/" + path;
		parent_ptr = parent_ptr->get_parent();
	}
	return "/" + path;
}

int Base::get_num()
{
	return num;
}

TYPE_SIGNAL	Base::get_signal()
{
	switch (get_num())
	{
	case 1:
		return SIGNAL_D(App::signal);
	case 2:
		return SIGNAL_D(Class2::signal);;
	case 3:
		return SIGNAL_D(Class3::signal);
	case 4:
		return SIGNAL_D(Class4::signal);
	case 5:
		return SIGNAL_D(Class5::signal);
	case 6:
		return SIGNAL_D(Class6::signal);
	}
	return nullptr;
}

TYPE_HANDLER Base::get_handler()
{
	switch (get_num())
	{
	case 1:
		return HANDLER_D(App::handler);
	case 2:
		return HANDLER_D(Class2::handler);;
	case 3:
		return HANDLER_D(Class3::handler);
	case 4:
		return HANDLER_D(Class4::handler);
	case 5:
		return HANDLER_D(Class5::handler);
	case 6:
		return HANDLER_D(Class6::handler);
	}
	return nullptr;
}

void Base::set_status_for_all()
{
	set_status(1);
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->set_status_for_all();
	}
}