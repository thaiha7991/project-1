#ifndef __graph_hpp__
#define __graph_hpp__

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, vector<string>> parseInput(ifstream &);

class Node {
private:
  string data;
  vector<Node *> ptrs;
public:
  Node();
  Node(string);
  // adds a new pointer to adj list
  void addPtr(Node *);
  // access node data
  string getData();
  vector<Node *> getPtrs();
};

class Graph {
private:
  // hash map of all nodes
  map<string, Node> nodes;
public:
  Graph();
  Graph(ifstream &);
  // access info about graph
  size_t getSize();
  vector<string> getNodeNames();
  vector<string> getPtrsNames(string);
  // adds either an edge or node
  // adding an edge will add nodes implicitly as needed
  bool addNode(string);
  bool addEdge(string, string);
  // utility function to show information
  void showNodes();
  void showEdges();
};

#endif
