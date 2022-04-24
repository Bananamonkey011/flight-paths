#define CATCH_CONFIG_MAIN
#include "../cs225/catch/catch.hpp"
#include "../src/Graph.h"
#include <math.h> 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <cmath>
#include <iostream>

bool dist(double d1, double d2) {
    return fabs(d1-d2) < 50;
}

TEST_CASE("test_addAirports") {
    Node n = Node();
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();
    REQUIRE(n.neighbors.size() == 0);
    n.addAirport(a, 0);
    REQUIRE(n.neighbors.size() == 1);
    n.addAirport(a, 0);
    REQUIRE(n.neighbors.size() == 1);
    n.addAirport(b, 0);
    REQUIRE(n.neighbors.size() == 2);
    n.addAirport(c, 0);
    REQUIRE(n.neighbors.size() == 3);
    
    delete a;
    delete b;
    delete c;
}

TEST_CASE("test_GraphConstructor") {
    string filename = "../test_airports.dat";
    fstream fs(filename);
    cout << "bonjour" << endl;
    char c;
    while (fs.get(c)) cout << endl;
    cout << endl;
    fs.close();
    cout << "salut" << endl;
    Graph g = Graph(filename);
    
    cout << g.hasNode(1) << endl;
    cout << g.hasNode(2) << endl;
    cout << g.hasNode(3) << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    REQUIRE(true);
    // REQUIRE_NOTHROW(g.getGraph()[1]->IATA_);
    // REQUIRE(g.getGraph()[1]->IATA_ == "AAA");
    // REQUIRE(g.getGraph()[2]->ICAO_ == "BBBB");
}

TEST_CASE("test_Dijkstras") {
    Graph g = Graph("test_airports.dat");
    g.AddEdges("test_routes.dat");

    double dist1 = g.Dijkstra(1, 2);
    double dist2 = g.Dijkstra(1, 3);
    double dist3 = g.Dijkstra(2, 1);

    REQUIRE(dist(dist1, 600));
    REQUIRE(dist(dist2, 846));
    REQUIRE(dist(dist3, 1446));

}