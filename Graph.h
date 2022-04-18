#pragma once

#include <map>
#include <set>
#include <vector>
#include <string>
#include "Node.h"

using namespace std;

class Graph {
    public:
        Graph();
        Graph(std::string file);
        void AddEdges(std::string file);
        // std::map<int, Node> getGraph();
    private:
        std::map<int, Node> graph;
};