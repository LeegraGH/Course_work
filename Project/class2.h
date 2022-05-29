#ifndef __CLASS2_H__
#define __CLASS2_H__

#include "other.h"

class Class2 : public Other
{
public:
	Class2(string name, Base* parent) : Other(name, parent, 2) {};
	void signal(string& text)
	{
		cout << "\nSignal from " << absolute_path();
		text += " (class: 2)";
	}
	void handler(string text)
	{
		cout << "\nSignal to " << absolute_path() << " Text: " << text;
	}
};

#endif