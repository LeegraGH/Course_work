#include "app.h"
#include "other.h"
int main()
{
	App app(nullptr);
	app.build_tree_obj();
	return app.execute_app();
}