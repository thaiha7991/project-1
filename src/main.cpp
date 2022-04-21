#include "graph.hpp"
#include "alg.hpp"

using namespace std;

bool input_valid_city(string message, string &input, vector<string> valid) {
  cout << message << " (case insensitive): ";
  getline(cin, input);
  transform(input.begin(), input.end(), input.begin(), ::tolower);
  if(find(valid.begin(), valid.end(), input) == valid.end())
    return false;
  return true; 
}

int main(int argc, char **argv) {

  if(argc != 2) {
    cout << "usage: " << argv[0] << " <input>" << endl;
    return 0;
  }
  
  ifstream file(argv[1]);
  if(!file.good()) {
    cout << argv[1] << "is not a valid path" << endl;
    return 0;
  }
  // initialize the graph class
  Graph cities(file);

  // create variables for the src / dst node, and all valid nodes
  vector<string> valid;
  string src, dst;

  // all valid nodes to select from
  valid = cities.getNodeNames();

  while(!input_valid_city("Enter source city", src, valid))
    cout << "not a valid source city" << endl;
 
  valid.erase(remove(valid.begin(), valid.end(), src), valid.end());
  
  while(!input_valid_city("Enter destination city", dst, valid))
    cout << "not a valid destination city" << endl;

  cities.showEdges();

  GraphPath shortest = shortestBFS(cities, src, dst);

  cout << "# of connections: " << shortest.second << endl;
  for(pair<string, string> kv : shortest.first)
    cout << kv.second << " => " << kv.first << endl;

  return 0;
}
