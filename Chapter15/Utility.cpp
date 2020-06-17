#include <string>
#include <iostream>
#include <fstream>

#include "Utility.h"
#include "TextQuery.h"

using namespace std;

string make_plural(int num, const string& prefix, const string& suffix) {
	if (num == 1)
		return prefix;
	else
		return prefix + suffix;
}

ostream& print(ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
		<< *(qr.file->begin() + num) << endl;
	return os;
}

void runQueries(ifstream& infile) {
	TextQuery tq(infile);

	while (true) {
		cout << "enther word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}