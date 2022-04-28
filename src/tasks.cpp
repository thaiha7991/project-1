#include "tasks.hpp"
#include "algos.hpp"
#include <iostream>

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
