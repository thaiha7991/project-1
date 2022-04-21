#include "alg.hpp"
#include "graph.hpp"

using namespace std;

map<string, vector<string>> parseInput(ifstream &file) {
 
  map<string, vector<string>> cities;
  string from, line;

  while(getline(file, line)) {

    transform(line.begin(), line.end(), line.begin(), ::tolower);

    if(line.rfind("from", 0) == 0) {
      from = line.substr(line.find(":") + 3, line.length() - 1);
      continue;
    }

    if(line.rfind("to", 0) == 0)
      line = line.substr(line.find(":") + 3, line.length() - 1);
    else
      line = line.substr(7, line.length() - 1);

    if(!from.empty() && !line.empty())
      cities[from].push_back(line);
  }

  // we dont need this anymore
  file.close();

  return cities;
}

Node::Node() {}
Node::Node(string data) {
  this->data = data;
}

void Node::addPtr(Node *ptr) {
  this->ptrs.push_back(ptr);
}
string Node::getData() { 
  return this->data; 
}
vector<Node *> Node::getPtrs() { 
  return this->ptrs; 
}

Graph::Graph() {}
Graph::Graph(ifstream &file) {
  for(pair<string, vector<string>> kv : parseInput(file)) {
    for(string edge : kv.second)
      this->addEdge(kv.first, edge);
  }
}

size_t Graph::getSize() { 
  return this->nodes.size(); 
}
  
vector<string> Graph::getNodeNames() {
  vector<string> nodes;
  for(pair<string, Node> kv : this->nodes)
    nodes.push_back(kv.first);
  return nodes;
}

vector<string> Graph::getPtrsNames(string name) {
  vector<string> nodes;
  for(Node * node : this->nodes[name].getPtrs())
    nodes.push_back(node->getData());
  return nodes;
}

bool Graph::addNode(string data) {
  if(this->nodes.count(data) > 0)
    return false;
  this->nodes[data] = Node(data);
  return true;
}

bool Graph::addEdge(string from, string to) {
  if(this->nodes.count(from) == 0)
    addNode(from);
  if(this->nodes.count(to) == 0)
    addNode(to);
  this->nodes[from].addPtr(&this->nodes[to]);
  return true;
}

void Graph::showNodes() {
  for(pair<string, Node> kv : this->nodes)
    cout << kv.first << ": " << kv.second.getPtrs().size() << endl;
}

void Graph::showEdges() {
  for(pair<string, Node> kv : this->nodes) {
    if(!kv.second.getPtrs().empty()) {
      cout << kv.first << ":" << endl;
      for(Node *node : kv.second.getPtrs())
        cout << "\t" << node->getData() << endl;
    }
  }
}

