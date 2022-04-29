//
//  main.cpp
//  project3110
//
//  Created by Thai Ha on 4/8/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <list>
using namespace std;

///Barker's classes
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
    bool reachability(int s, int d);
};

std::vector<std::string> parse(std::string path) {
  std::ifstream file(path);
  std::vector<std::string> nodes;
  return nodes;
}
///Barker's

//graph's reachability function. I believe this function will be helpful becuz all 4 tasks ask to return a message if no such route is found
bool Graph::reachability(int s, int d){
    //base case
    if (s==d)
        return true;
    
    //mark vertices that have not been visited
    bool *visited = new bool [V];
    for (int i = 0; i<V; i++)
        visited[i] = false;
    
    //create a queue for BFS
    list<int> queue;
    
    //mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    
    //this gets all adjacent vertices of a vertex
    list<int>::iterator i;
    while (!queue.empty()){
        //dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
        
        //get all adjacent vertices of the dequeued vertex s
        //if an adjacent has not been visited, then that adjacent vertex is marked visted and enqueued
        for (i = adj[s].begin(); i != adj[s].end(); ++i){
            if (*i ==d)
                return true;
            if else (!visited[*i]){
                visited[*i] = true;
                queue.push_back(*1);
            }
        }
    }
    return false;
}
 


                         

int main(int argc, const char * argv[]) {
    // insert code here...
    if(argc != 2) {
        std::cout <<"usage: " <<argv[0]<< "<input>"<<std::endl;
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
