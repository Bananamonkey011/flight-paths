#pragma once

#include <map>
#include <set>
#include <string>
#include "Node.h"

using namespace std;

class Graph {
    public:
        Graph();
        Graph(std::string file);
        void AddEdges(std::string file);
    private:
        std::map<int,Node> points;
};