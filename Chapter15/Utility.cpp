#include <string>
#include <iostream>
#include <fstream>

#include "Utility.h"

using namespace std;

string make_plural(int num, const string& prefix, const string& suffix) {
	if (num == 1)
		return prefix;
	else
		return prefix + suffix;
}