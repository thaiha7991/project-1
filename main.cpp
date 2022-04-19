#include <fstream>
#include <vector>
#include <map>
#include "graph.hpp"

using namespace std;

map<string, vector<string>> parse_input_file(const char *path) {
  
  ifstream file(path); // user will use an input file
  
  // need a hashmap to group data accordingly
  map<string, vector<string>> cities;
  string from, line; // strings to hold values from file
  
  // read file line by line
  while(getline(file, line)) {
    
    if(line.rfind("From", 0) == 0) { // set "from"
      from = line.substr(line.find(":") + 3, line.length() - 1);
      continue; // no need to go on to the next lines
    }
    
    if(line.rfind("To", 0) == 0) // line is next to "To" keyword
      line = line.substr(line.find(":") + 3, line.length() - 1);
    else // line is not next to "To", so we need to cut out more space
      line = line.substr(7, line.length() - 1);

    if(!from.empty() && !line.empty()) // if "from" is set, add city
      cities[from].push_back(line);
  }
  
  // close handle
  file.close();

  return cities; // give the grouped data back to the main scope
}

int main(int argc, char **argv) {

  if(argc != 2) {
    cout << "usage: " << argv[0] << " <input>" << endl;
    return 0;
  }
  
  map<string, vector<string>> cities;
  Graph g;
  
  cities = parse_input_file(argv[1]);

  for(pair<string, vector<string>> kv : cities) {
    for(string edge : kv.second)
      g.addEdge(kv.first, edge);
  }

  g.showNodes();
  //g.showEdges();

  return 0;
}
