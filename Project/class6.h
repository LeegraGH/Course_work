#ifndef __CLASS6_H__
#define __CLASS6_H__

#include "other.h"

class Class6 : public Other
{
public:
	Class6(string name, Base* parent) : Other(name, parent, 6) {};
	void signal(string& text)
	{
		cout << "\nSignal from " << absolute_path();
		text += " (class: 6)";
	}
	void handler(string text)
	{
		cout << "\nSignal to " << absolute_path() << " Text: " << text;
	}
};

#endif