#include "alg.hpp"

#include <queue>
#include <set>

GraphPath shortestBFS(Graph g, string src, string dst) {

  queue<NodeWeight> nodes;
  map<string, string> paths;
  set<string> visit;
  NodeWeight node;

  nodes.push({src, 0});

  while(nodes.size() > 0) {
    
    node = nodes.front();
    nodes.pop();
    
    if(node.first == dst)
      return { paths, node.second };
    
    for(string name : g.getPtrsNames(node.first)) {
      if(visit.count(name) == 0) {
        paths[name] = node.first;
        nodes.push({name, node.second + 1});
        visit.insert(name);
      }
    }
  }

  return { paths, 0 };
}
