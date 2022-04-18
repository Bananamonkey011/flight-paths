#include "Traversals.h"

#include <vector>
#include <queue>

using namespace std;

vector<Node> Traversals::bfs(int depart_id, int arrival_id) {
    vetor<bool> visited;
    for (int i = 0; i < graph.size(); i++) {
        visited[i] = false;
    }
    Node departure = graph[depart_id];
}