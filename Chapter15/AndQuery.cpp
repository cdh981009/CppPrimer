#include <algorithm>
#include <iterator>

#include "Query.h"

using namespace std;

QueryResult AndQuery::eval(const TextQuery& text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(),
					 right.begin(), right.end(),
					 inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}