#ifndef __graph_hpp__
#define __graph_hpp__

// this file defines the prototype
// for the graph data structure

#include <fstream>
#include <string>
#include <set>
#include <map>

using namespace std;

class Graph {
private:
  // hash map of all nodes
  map<string, set<string>> nodes;
public:
  Graph();
  Graph(ifstream &);
  // access info about graph
  size_t size();
  // access nodes and node neighbors
  set<string> getNodes();
  set<string> getNodes(string);
};

#endif
