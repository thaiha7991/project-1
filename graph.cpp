#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

class Node {
private:
  // data for the node will be contained 
  //  in a string called "node"
  // nodes will have a list (vector)
  //  of pointers to the other nodes it
  //  points to called "ptrs"
  std::string data;
  std::vector<Node *> ptrs;
public:
  Node() {} // default constructor
  Node(std::string data) { // constructor
    this->data = data;     // that initializes with data
  }
  // nodes must be able to add a new pointer to their list
  // of connections
  void addPtr(Node *ptr) {
    this->ptrs.push_back(ptr);
  }
  // getter functions (node data should be immutable)
  std::string getData() { return this->data; }
  std::vector<Node *> getPtrs() { return this->ptrs; }
};

class Graph {
private:
  // use a map, mapping the data within the
  // node to the node itself (this is a little redundant
  // but allows for faster lookup, and cleaner
  // implementations ???)
  std::map<std::string, Node> nodes; // key: node.data, value: node
public:
  // Add Node (addNode):
  //  adds a new node to the graph, the new node will
  //  not have any connections, and be mapped to the
  //  argument "data" in the nodes map
  void addNode(std::string data) {
    this->nodes[data] = Node(data); // create a new node, add it to the graph
  }
  // Add Edge (addEdge):
  //  adds a directed edge between two nodes within the graph
  void addEdge(std::string from, std::string to) {
    this->nodes[from].addPtr(&this->nodes[to]); // add the pointer to the node
  }
  // utility to visualize the edges in the graph
  void showEdges() {
    std::map<std::string, Node>::iterator i;
    for(i = this->nodes.begin(); i != this->nodes.end(); i++) {
      Node node = i->second;
      std::cout << node.getData() << ":";
      std::vector<Node *> edges = node.getPtrs();
      for(size_t j = 0; j < edges.size(); j++) {
        std::cout << " " << edges[j]->getData();
      }
      std::cout << std::endl;
    }
  }
};

std::vector<std::string> parse(std::string path) {
  std::ifstream file(path);
  std::vector<std::string> nodes;
  return nodes;
}

int main(int argc, char **argv) {

  if(argc != 2) {
    std::cout << "usage: " << argv[0] << " <input>" << std::endl;
    return 0;
  }

  std::vector<std::string> input = parse(argv[1]);

  Graph g = Graph();

  g.addNode("A");
  g.addNode("B");
  g.addNode("C");

  g.addEdge("A", "B");
  g.addEdge("A", "C");
  g.addEdge("C", "B");

  g.showEdges();

  return 0;
}
