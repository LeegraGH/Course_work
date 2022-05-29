#include "app.h"

/*void App::build_tree_obj()
{
	string parent_coordinate;
	string child_name;
	int num;
	cin >> parent_coordinate;
	set_name(parent_coordinate);
	Base* parent_ptr = this;
	Base* child_ptr = nullptr;
	while (true)
	{
		cin >> parent_coordinate;
		if (parent_coordinate == "endtree") break;
		cin >> child_name >> num;
		parent_ptr = get_obj_by_coordinate(parent_coordinate);
		if (parent_ptr == nullptr)
		{
			cout << "Object tree" << endl;
			cout << get_name();
			string spaces = "";
			print(spaces);
			cout << "\nThe head object " << parent_coordinate << " is not found";
			exit(0);
		}
		switch (num)
		{
		case 2:
		{
			child_ptr = new Class2(child_name, parent_ptr);
			break;
		}
		case 3:
		{
			child_ptr = new Class3(child_name, parent_ptr);
			break;
		}
		case 4:
		{
			child_ptr = new Class4(child_name, parent_ptr);
			break;
		}
		case 5:
		{
			child_ptr = new Class5(child_name, parent_ptr);
			break;
		}
		case 6:
		{
			child_ptr = new Class6(child_name, parent_ptr);
			break;
		}
		}
	}
}*/

void App::build_tree_obj()
{
	string parent_coordinate;
	string child_name;
	int num;
	cin >> parent_coordinate;
	set_name(parent_coordinate);
	Base* parent_ptr = this;
	Base* child_ptr = nullptr;
	while (true)
	{
		cin >> parent_coordinate;
		if (parent_coordinate == "endtree") break;
		cin >> child_name >> num;
		parent_ptr = get_obj_by_coordinate(parent_coordinate);
		if (parent_ptr == nullptr)
		{
			cout << "Object tree" << endl;
			cout << get_name();
			string spaces = "";
			print(spaces);
			cout << "\nThe head object " << parent_coordinate << " is not found";
			exit(0);
		}
		switch (num)
		{
		case 2:
		{
			child_ptr = new Class2(child_name, parent_ptr);
			break;
		}
		case 3:
		{
			child_ptr = new Class3(child_name, parent_ptr);
			break;
		}
		case 4:
		{
			child_ptr = new Class4(child_name, parent_ptr);
			break;
		}
		case 5:
		{
			child_ptr = new Class5(child_name, parent_ptr);
			break;
		}
		case 6:
		{
			child_ptr = new Class6(child_name, parent_ptr);
			break;
		}
		}
	}
	string signal_obj, target_obj;
	while (true)
	{
		cin >> signal_obj;
		if (signal_obj == "end_of_connections") break;
		cin >> target_obj;
		get_obj_by_coordinate(signal_obj)->set_connect(get_obj_by_coordinate(signal_obj)->get_signal(), get_obj_by_coordinate(target_obj), get_obj_by_coordinate(target_obj)->get_handler());
	}
}

/*int App::execute_app()
{
	string command;
	string coordinate;
	cout << "Object tree" << endl;
	cout << get_name();
	string spaces = "";
	print(spaces);
	while (true)
	{
		cin >> command;
		if (command == "SET")
		{
			cin >> coordinate;
			if (get_obj_by_coordinate(coordinate) != nullptr)
			{
				set_current(get_obj_by_coordinate(coordinate));
				cout << endl << "Object is set: " << get_current()->get_name();
			}
			else
			{
				cout << endl << "Object is not found: " << get_current()->get_name() << " " << coordinate;
			}
		}
		else if (command == "FIND")
		{
			cin >> coordinate;
			cout << endl << coordinate;
			if (get_obj_by_coordinate(coordinate) != nullptr)
			{
				cout << "     Object name: " << get_obj_by_coordinate(coordinate)->get_name();
			}
			else
			{
				cout << "     Object is not found";
			}
		}
		else if (command == "END")
		{
			return 0;
		}
	}
}*/

/*int App::execute_app()
{
	cout << "Object tree" << endl;
	cout << get_name();
	string spaces = "";
	print(spaces);
	string name_obj;
	int status;
	Base* obj;
	cout << endl;
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
}*/

int App::execute_app()
{
	cout << "Object tree" << endl;
	cout << get_name();
	string spaces = "";
	print(spaces);
	string command;
	string coordinate;
	string target_coordinate;
	string text;
	int status;
	set_status_for_all();
	while (true)
	{
		cin >> command;
		if (command == "END") return 0;
		else if (command == "EMIT")
		{
			cin >> coordinate;
			getline(cin, text);
			if (get_obj_by_coordinate(coordinate) != nullptr)
			{
				get_obj_by_coordinate(coordinate)->emit_signal(get_obj_by_coordinate(coordinate)->get_signal(), text);
			}
			else
			{
				cout << "\nObject " << coordinate << " not found";
				continue;
			}
		}
		else if (command == "SET_CONNECT")
		{
			cin >> coordinate >> target_coordinate;
			if (get_obj_by_coordinate(coordinate) != nullptr && get_obj_by_coordinate(target_coordinate) != nullptr)
			{
				get_obj_by_coordinate(coordinate)->set_connect(get_obj_by_coordinate(coordinate)->get_signal(), get_obj_by_coordinate(target_coordinate), get_obj_by_coordinate(target_coordinate)->get_handler());
			}
			else if (get_obj_by_coordinate(coordinate) == nullptr)
			{
				cout << "\nObject " << coordinate << " not found";
				continue;
			}
			else
			{
				cout << "\nHandler object " << target_coordinate << " not found";
				continue;
			}
		}
		else if (command == "DELETE_CONNECT")
		{
			cin >> coordinate >> target_coordinate;
			if (get_obj_by_coordinate(coordinate) != nullptr && get_obj_by_coordinate(target_coordinate) != nullptr)
			{
				get_obj_by_coordinate(coordinate)->delete_connect(get_obj_by_coordinate(coordinate)->get_signal(), get_obj_by_coordinate(target_coordinate), get_obj_by_coordinate(target_coordinate)->get_handler());
			}
			else if (get_obj_by_coordinate(coordinate) == nullptr)
			{
				cout << "\nObject " << coordinate << " not found";
				continue;
			}
			else
			{
				cout << "\nHandler object " << target_coordinate << " not found";
				continue;
			}
		}
		else if (command == "SET_CONDITION")
		{
			cin >> coordinate >> status;
			if (get_obj_by_coordinate(coordinate) != nullptr)
			{
				get_obj_by_coordinate(coordinate)->set_status(status);
			}
			else
			{
				cout << "\nObject " << coordinate << " not found";
				continue;
			}
		}
	}
}