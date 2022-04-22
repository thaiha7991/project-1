#include <algorithm>

#include "graph.hpp"

Graph::Graph() {}
Graph::Graph(ifstream &file) {

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

    if(!line.empty() && this->nodes.count(line) == 0)
      this->nodes[line] = {};

    if(!from.empty() && !line.empty())
      this->nodes[from].insert(line);
  }

  // we dont need this anymore
  file.close();
}

size_t Graph::size() { 
  return this->nodes.size(); 
}

set<string> Graph::getNodes(string node) {
  return this->nodes[node];
}

set<string> Graph::getNodes() {
  set<string> nodes;
  for(pair<string, set<string>> kv : this->nodes)
    nodes.insert(kv.first);
  return nodes;
}

