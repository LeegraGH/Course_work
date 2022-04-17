#include "app.h"

void App::build_tree_obj()
{
	string parent_name;
	string child_name;
	int num=1;
	cin >> parent_name;
	set_name(parent_name);
	Base* parent_ptr = this;
	Base* last_parent_ptr = this;
	Base* child_ptr = nullptr;
	while (true)
	{
		cin >> parent_name;
		if (parent_name == "endtree") break;
		cin >> child_name >> num;
		if (child_ptr != nullptr && child_ptr->get_name() == parent_name) parent_ptr = child_ptr;
		else if (parent_ptr->get_name() != parent_name)
		{
			last_parent_ptr = parent_ptr;
			parent_ptr = get_obj_by_name(parent_name);
		}
		child_ptr = new Other(child_name, parent_ptr, num);
	}
}
int App::execute_app()
{
	cout << "Object tree" << endl;
	cout << get_name() << endl;
	print();
	string name_obj;
	int status;
	Base* obj;
	while (cin >> name_obj >> status)
	{
		obj = get_obj_by_name(name_obj);
		obj->set_status(status);
	}
	cout << "The tree of objects and their readiness" << endl;
	cout << get_name();
	if (status == 0) cout << " is not ready" << endl;
	else cout << " is ready" << endl;
	print_readiness();
	return 0;
}