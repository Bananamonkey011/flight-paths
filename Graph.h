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
    private:
        std::set<Node> visited;
};