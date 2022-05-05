#include <algorithm>
#include <iostream>
#include <vector>

#include "graph.hpp"
#include "algos.hpp"
#include "tasks.hpp"

void showFlights(vector<string>);

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

  vector<string> route;
  set<string> accepted;

  string input, a, b, c;
  unsigned int x;
  
  while(true) {
   
    accepted = cities.getNodesWithEdges();

    cout << "1) x connections from a to b" << endl;
    cout << "2) from a to d through b and c" << endl;
    cout << "3) around the world and back" << endl;
    cout << "4) middle ground" << endl;
    cout << "l) list all nodes" << endl;
    cout << "i) list all inner nodes (nodes with outbound connections)" << endl;
    cout << "q) quit" << endl;
    while(!validInput("select from menu", input, {"1","2","3","4","l","i","q"}))
      cout << "not a valid option" << endl;

    if(input == "q")
      break;

    if(input == "l") {
      for(string city : cities.getNodes())
        cout << city << endl;
    } else if(input == "li") {
      for(string city : cities.getNodesWithEdges())
        cout << city << endl; 
    }

    // 1 ) city a to city b with less than x connections
    if(input == "1") {
          
      while(!validInput("[Task 1] Enter city A (inner node)", a, accepted))
        cout << "not a valid city" << endl;
      
      accepted = cities.getNodes(); // valid choices are now all nodes
      accepted.erase(a);
      
      while(!validInput("[Task 1] Enter city B (not city A)", b, accepted)) {
        if(a == b)
          cout << "You are already here" << endl;
        else
          cout << "not a valid city" << endl;
      }

      while(!valueInput("[Task 1] Enter desired # of connections", x))
        cout << "not a valid number" << endl;

      route = task1(cities, a, b, x);

    } else if(input == "2") {
      // thai
      while(!validInput("[Task 2] Enter city A", a, accepted))
          cout << "not a valid city" << endl;
        
        accepted = cities.getNodes(); // valid choices are now all nodes
        accepted.erase(a);
        
        while(!validInput("[Task 2] Enter city D (not city A)", d, accepted)) {
          if(a == d)
            cout << "You are already here" << endl;
          else
            cout << "not a valid city" << endl;
        }
        while(!valueInput("[Task 2] Enter city B", b, accepted))
          cout << "not a valid city" << endl;
        while(!valueInput("[Task 2] Enter city C", c, accepted))
            cout << "not a valid city" << endl;
            
        route = task2(cities, a, b, c, d);
    } else if(input == "3") {
      
      while(!validInput("[Task 3] Enter starting city", a, accepted))
        cout << "not a valid starting node" << endl;

      route = task3(cities, a);
    
    } else if(input == "4")
      cout << "not ready yet :S" << endl;

    showFlights(route);
  }


  return 0;
}

void showFlights(vector<string> route) {
  if(route.empty()) {
    cout << "No path exists" << endl;
  } else {
    cout << "flights taken: " << route.size() - 1 << endl;
    cout << route[0]; // display path
    for(size_t i = 1; i < route.size(); i++)
      cout << " <-(" << route.size() - i << ")- " << route[i];
    cout << endl;
  }
}
