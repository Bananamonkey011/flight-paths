#include "src/Graph.h"

#include <iostream>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Graph g = Graph();
    g.AddEdges();
    cout << g.hasNode(1393) << endl;
    return 0;
}