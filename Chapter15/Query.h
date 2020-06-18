#pragma once

#include <string>
#include <memory>
#include <iostream>

#include "TextQuery.h"
#include "QueryResult.h"

class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery& t) {
		return q->eval(t);
	}
	std::string rep() const {
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) : q(query) { }
	std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream& os, const Query& query) {
	return os << query.rep();
}

class WordQuery : public Query_base {
	friend class Query;
	WordQuery(const std::string& s) : query_word(s) { }
	QueryResult eval(const TextQuery& t) const {
		return t.query(query_word);
	}
	std::string rep() const { return query_word; }
	std::string query_word;
};

inline Query::Query(const std::string& s) : q(new WordQuery(s)) { }
