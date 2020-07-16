#include <iostream>

#include "Util.h"
#include "shared_pointer.h"
#include "template.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main() {
	int i = 42, * p = &i;
	const int ci = 0, * p2 = &ci;
	g(42);
	g(p);
	g(ci);
	g(p2);
	f(42);
	f(p);
	f(ci);
	f(p2);
	return 0;
}
