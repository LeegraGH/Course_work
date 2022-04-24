#include "base.h"
Base::Base(Base* parent, string name)
{
	this->name = name;
	this->parent = parent;
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
				parent->children.erase(parent ->
					children.begin() + i);
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
			break;
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
	while (obj->parent != nullptr)
	{
		if (obj->parent->status == 0) return;
		obj = obj->parent;
	}
	this->status = 1;
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