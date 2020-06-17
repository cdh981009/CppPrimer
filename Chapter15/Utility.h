#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "QueryResult.h"

std::string make_plural(int num, const std::string& prefix, const std::string& suffix);

std::ostream& print(std::ostream& os, const QueryResult& qr);

void runQueries(std::ifstream& infile);