#ifndef __tasks_hpp__
#define __tasks_hpp__

#include <set>
#include <vector>
#include <string>

#include "graph.hpp"

bool validInput(string, string &, set<string>);
bool valueInput(string, unsigned int &);

vector<string> task1(Graph, string, string, unsigned int);
vector<string> task2(Graph, string, string, string, string);
vector<string> task3(Graph, string);
set<vector<string>> task4(Graph, string, string, string);

#endif
