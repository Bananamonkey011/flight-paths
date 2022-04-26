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

double distance(Node *a1, Node *a2) {
    double lat1 = M_PI / 180 * a1->lat_;
    double long1 = M_PI / 180 * a1->long_;
    double lat2 = M_PI / 180 * a2->lat_;
    double long2 = M_PI / 180 * a2->long_;

    double ans = pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2), 2);

    ans = 2 * asin(sqrt(ans));

    double R = 3956;
    ans = ans * R;

    return ans;
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
    string filename = "tests/test_airports.dat";
    Graph g = Graph(filename);
    
    REQUIRE(g.getGraph()[1]->IATA_ == "AAA");
    REQUIRE(g.getGraph()[2]->ICAO_ == "BBBB");
}

TEST_CASE("test_Dijkstras_simple") {
    string nodes_filename = "tests/test_airports.dat";
    Graph g = Graph(nodes_filename);
    string edges_filename = "tests/test_routes_simple.dat";
    g.AddEdges(edges_filename);

    double dist1 = g.Dijkstra(1, 2);
    double dist2 = g.Dijkstra(1, 3);
    double dist3 = g.Dijkstra(2, 3);

    REQUIRE(dist1 == distance(g.getNode(1), g.getNode(2)));
    REQUIRE(dist2 == distance(g.getNode(1), g.getNode(3)));
    REQUIRE(dist3 == distance(g.getNode(2), g.getNode(3)));
}

TEST_CASE("test_Dijkstras_medium") {
    string nodes_filename = "tests/test_airports.dat";
    Graph g = Graph(nodes_filename);
    string edges_filename = "tests/test_routes_medium.dat";
    g.AddEdges(edges_filename);

    double dist1 = g.Dijkstra(1, 2);

    REQUIRE(dist1 == distance(g.getNode(1), g.getNode(3)) + distance(g.getNode(2), g.getNode(3)));
}

TEST_CASE("test_Dijkstras_hard") {
    string nodes_filename = "tests/test_airports.dat";
    Graph g = Graph(nodes_filename);
    string edges_filename = "tests/test_routes_hard.dat";
    g.AddEdges(edges_filename);

    double dist1 = g.Dijkstra(1, 2);

    REQUIRE(dist1 == distance(g.getNode(1), g.getNode(3)) + distance(g.getNode(2), g.getNode(3)));
}