#ifndef __CLASS5_H__
#define __CLASS5_H__

#include "other.h"

class Class5 : public Other
{
public:
	Class5(string name, Base* parent) : Other(name, parent, 5) {};
	void signal(string& text)
	{
		cout << "\nSignal from " << absolute_path();
		text += " (class: 5)";
	}
	void handler(string text)
	{
		cout << "\nSignal to " << absolute_path() << " Text: " << text;
	}
};

#endif