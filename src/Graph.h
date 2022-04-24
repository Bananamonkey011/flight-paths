#pragma once

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <cmath>
#include <iostream>
#include "Node.h"

using namespace std;

class Graph {
public:
    Graph();
    Graph(string file);
    void AddEdges();
    void AddEdges(string file);
    double Dijkstra(int depart_id, int arrival_id);
    Node* getNode(int key);
    bool hasNode(int key);

    map<int, Node*>& getGraph();

private:
    map<int, Node*> graph;
    double distance(Node* a1, Node* a2);
};