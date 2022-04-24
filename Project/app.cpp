#include "app.h"
void App::build_tree_obj()
{
	string parent_name;
	string child_name;
	int num;
	cin >> parent_name;
	set_name(parent_name);
	Base* parent_ptr = this;
	Base* child_ptr = nullptr;
	while (true)
	{
		cin >> parent_name;
		if (parent_name == "endtree") break;
		cin >> child_name >> num;
		parent_ptr = get_obj_by_name(parent_name);
		switch (num)
		{
		case 2:
		{
			child_ptr = new Class2(child_name,
				parent_ptr);
			break;
		}
		case 3:
		{
			child_ptr = new Class3(child_name,
				parent_ptr);
			break;
		}
		case 4:
		{
			child_ptr = new Class4(child_name,
				parent_ptr);
			break;
		}
		case 5:
		{
			child_ptr = new Class5(child_name,
				parent_ptr);
			break;
		}
		case 6:
		{
			child_ptr = new Class6(child_name,
				parent_ptr);
			break;
		}
		}
	}
}
int App::execute_app()
{
	cout << "Object tree" << endl;
	cout << get_name();
	string spaces = "";
	print(spaces);
	cout << endl;
	string name_obj;
	int status;
	Base* obj;
	while (cin >> name_obj)
	{
		cin >> status;
		obj = get_obj_by_name(name_obj);
		obj->set_status(status);
	}
	cout << "The tree of objects and their readiness" << endl;
	cout << get_name();
	print_readiness(spaces);
	return 0;
}