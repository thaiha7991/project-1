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

//find path from A to D thru B and C
// most likely return the shortest path from a to d then attempt to find node b and c in the discovered path
vector<string> task2(Graph g, string a, string b, string c, string d)
{
    GraphPath shortestPathAD;

    map<string, string>pathB;
    map<string, string>pathC;
    vector<string>path;
    string node;
    
    shortestPathAD = BFS(g, a, d); //search shortest path from a to b
    
    if (shortestPathAD.find (b) && shortestPathAD.find(c))
        return path;
    else
        cout << "There is no path om city “A” to city “D” through city “B” and “C”."<<endl;
    return 0;
}
