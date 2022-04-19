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
    Graph(std::string file);
    void AddEdges(std::string file);
    vector<Node*> Dijkstra(int depart_id, int arrival_id);


private:
    map<int, Node *> graph;
    double distance(Node* a1, Node* a2);
};