#include <algorithm>
#include <iostream>
#include <vector>

#include "graph.hpp"
#include "algos.hpp"
#include "tasks.hpp"

bool input_valid_task(string &);
bool input_valid_city(string, string &, set<string>);

int main(int argc, char **argv) {

  cout << "Welcome to " << string(argv[0]).substr(2) << endl;
  if(argc != 2) {
    cout << "usage: " << argv[0] << " <input>" << endl;
    return 0;
  }
  
  ifstream file(argv[1]);
  if(!file.good()) {
    cout << argv[1] << " is not a file" << endl;
    return 0;
  }
  // initialize the graph class
  Graph cities(file);
  string input;
  
  cout << "1. x connections from a to b" << endl;
  cout << "2. from a to d through b and c" << endl;
  cout << "3. around the world and back" << endl;
  cout << "4. middle ground" << endl;
  while(!input_valid_task(input))
    cout << "not a valid option" << endl;
  
  // 1 ) city a to city b with less than x connections
  if(input == "1") {
    
    vector<string> nodes;
    set<string> valid;
    string a, b, input;
    unsigned int x;
  
    valid = cities.getNodesWithEdges();
    
    while(!input_valid_city("[Task 1] Enter city A", a, valid))
      cout << "not a valid city" << endl;
    
    valid = cities.getNodes(); // valid choices are now all nodes
    valid.erase(a);
    
    while(!input_valid_city("[Task 1] Enter city B", b, valid)) {
      if(a == b)
        cout << "You are already here" << endl;
      else
        cout << "not a valid city" << endl;
    }

    cout << "[Task 1] Enter desired minimum number of connections: ";
    getline(cin, input); 
    x = stoul(input, nullptr, 0);

    cout << "[Task 1] starting..." << endl;
    nodes = task1(cities, a, b, x);
    
    if(nodes.empty()) {
      cout << "[Task 1] No path exists" << endl;
      return 0;
    }
    
    cout << "[Task 1] Actual jumps: " << nodes.size() - 1 << endl;
    cout << "[Task 1] " << nodes[0]; // display path
    for(size_t i = 1; i < nodes.size(); i++)
      cout << " <-(" << nodes.size() - i << ")- " << nodes[i];
    cout << endl;
  } else if(input == "2") {

  }
  
  return 0;
}

bool input_valid_task(string &input) {
  set<string> choices = { "1", "2", "3", "4" };
  cout << "Select (1-4): ";
  getline(cin, input);
  return (bool) choices.count(input);
}

bool input_valid_city(string message, string &input, set<string> valid) {
  cout << message << " (case insensitive): ";
  getline(cin, input);
  transform(input.begin(), input.end(), input.begin(), ::tolower);
  if(find(valid.begin(), valid.end(), input) == valid.end())
    return false;
  return true; 
}
