#ifndef __alg_hpp__
#define __alg_hpp__

#include "graph.hpp"

typedef pair<string, unsigned int> NodeWeight;
typedef pair<map<string, string>, unsigned int> GraphPath;

GraphPath shortestBFS(Graph, string, string);

#endif
