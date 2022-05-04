#include "tasks.hpp"
#include "algos.hpp"
#include <iostream>

bool validInput(string message, string &input, set<string> valid) {
  cout << message << ": ";
  getline(cin, input);
  return (bool) valid.count(input);
}

bool valueInput(string message, unsigned int &x) {
  cout << message << ": ";
  try {
    string input;
    getline(cin, input);
    x = stoul(input, nullptr, 0);
  } catch (...) {
    return false;
  }
  return true;
}

vector<string> task1(Graph g, string a, string b, unsigned int x) {
  
  GraphPath shortestPath;
  map<string, string> paths;
  vector<string> path;
  string node;

  shortestPath = BFS(g, a, b);

  if(shortestPath.second > x)
    return {};

  node = shortestPath.first[b];
  path = { b, node };
  while(node != a) {
    node = shortestPath.first[node];
    path.push_back(node);
  }

  return path;
}

vector<string> task3(Graph g, string a) {
  return {};
}
