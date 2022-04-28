#ifndef __algos_hpp__
#define __algos_hpp__

// this file defines the algorithms used
// in this project

#include "graph.hpp"

typedef pair<string, unsigned int> NodeWeight;
typedef pair<map<string, string>, unsigned int> GraphPath;

GraphPath BFS(Graph, string, string);

#endif
