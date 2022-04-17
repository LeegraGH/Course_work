#include "app.h"
#include "other.h"

int main()
{
	App app(nullptr,1);
	app.build_tree_obj();
	return app.execute_app();
}