#ifndef __CLASS3_H__
#define __CLASS3_H__

#include "other.h"

class Class3 : public Other
{
public:
	Class3(string name, Base* parent) : Other(name, parent, 3) {};
	void signal(string& text)
	{
		cout << "\nSignal from " << absolute_path();
		text += " (class: 3)";
	}
	void handler(string text)
	{
		cout << "\nSignal to " << absolute_path() << " Text: " << text;
	}
};

#endif