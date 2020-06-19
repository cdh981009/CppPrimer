#include <iostream>
#include <sstream>

#include "TextQuery.h"
#include "QueryResult.h"
#include "Utility.h"

using namespace std;

TextQuery::TextQuery(ifstream& is) : file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto& lines = wm[word]; // pointer
			if (!lines) { // if word is not in wm already, the pointer is null
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream& operator<<(ostream& os, const QueryResult& qr) {
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
		cout << tq.query(s) << endl;
	}
}