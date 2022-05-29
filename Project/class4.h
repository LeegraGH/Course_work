#ifndef __CLASS4_H__
#define __CLASS4_H__

#include "other.h"

class Class4 : public Other
{
public:
	Class4(string name, Base* parent) : Other(name, parent, 4) {};
	void signal(string& text)
	{
		cout << "\nSignal from " << absolute_path();
		text += " (class: 4)";
	}
	void handler(string text)
	{
		cout << "\nSignal to " << absolute_path() << " Text: " << text;
	}
};

#endif