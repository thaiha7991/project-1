#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Node {
private:
  // data for the node will be contained 
  //  in a string called "node"
  // nodes will have a list (vector)
  //  of pointers to the other nodes it
  //  points to called "ptrs"
  string data;
  vector<Node *> ptrs;
public:
  Node() {} // default constructor
  Node(string data) { // constructor
    this->data = data;     // that initializes with data
  }
  // nodes must be able to add a new pointer to their list
  // of connections
  void addPtr(Node *ptr) {
    this->ptrs.push_back(ptr);
  }
  // getter functions (node data should be immutable)
  string getData() { return this->data; }
  vector<Node *> getPtrs() { return this->ptrs; }
};

class Graph {
private:
  // use a map, mapping the data within the
  // node to the node itself (this is a little redundant
  // but allows for faster lookup, and cleaner
  // implementations ???)
  map<string, Node> nodes; // key: node.data, value: node
public:
  size_t getSize() { return this->nodes.size(); }
  // Add Node (addNode):
  //  adds a new node to the graph, the new node will
  //  not have any connections, and be mapped to the
  //  argument "data" in the nodes map
  bool addNode(string data) {
    if(this->nodes.count(data) > 0)
      return false; // error key already exists
    this->nodes[data] = Node(data); // create a new node, add it to the graph
    return true;
  }
  // Add Edge (addEdge):
  //  adds a directed edge between two nodes within the graph
  bool addEdge(string from, string to) {
    if(this->nodes.count(from) == 0)
      addNode(from); // add the uninitialized node
    if(this->nodes.count(to) == 0)
      addNode(to); // add the uninitialized node
    this->nodes[from].addPtr(&this->nodes[to]); // add the pointer to the node
    return true;
  }
  // utility to visualize the nodes in the graph
  void showNodes() {
    for(pair<string, Node> kv : this->nodes)
      cout << kv.first << ": " << kv.second.getPtrs().size() << endl;
  }
  // utility to visualize the edges in the graph
  void showEdges() {
    for(pair<string, Node> kv : this->nodes) {
      if(!kv.second.getPtrs().empty()) {
        cout << kv.first << ": ";
        for(Node *node : kv.second.getPtrs())
          cout << "\t" << node->getData() << endl;
      }
    }
  }
};
