#include "src/Graph.h"

#include <iostream>

using namespace std;

int main() {
    cout<<"Hello, World!"<<endl;
    Graph g = Graph("test_airports.dat");
    
    cout << (g.getGraph()[1]->IATA_ == "AAA") << endl;
    cout << (g.getGraph()[2]->ICAO_ == "BBBB") << endl;
    return 0;
}
