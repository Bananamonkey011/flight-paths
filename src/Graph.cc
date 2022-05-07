#include "Graph.h"
#include <queue>
#include <iostream>
#include <stack>
#include <set>
using namespace std;

Graph::Graph() { // TODO(): HANDLE INCORRECT DATA
    string datapath = "src/airports.dat";
    fstream datafile(datapath);
    while (datafile.is_open() && datafile.good()) {
        string idx, name, loc, country, IATA, ICAO, lat, lon, alt, temp;
        getline(datafile, idx, ',');     // index
        getline(datafile, name, ',');    // name
        getline(datafile, loc, ',');     // location
        getline(datafile, country, ','); // country
        getline(datafile, IATA, ',');    // country
        getline(datafile, ICAO, ',');    // country
        getline(datafile, lat, ',');     // latitude
        getline(datafile, lon, ',');     // longitude
        getline(datafile, alt, ',');     // altitude
        getline(datafile, temp, ',');    // timezone
        getline(datafile, temp, ',');    // Daylight savings time
        getline(datafile, temp, ',');    // Database timezone
        getline(datafile, temp, ',');    // type of station
        getline(datafile, temp);         // source

        // create node using given information
        try {
            int alt_ = isNbr(alt) ? stoi(alt) : -1;
            if (IATA != "\\N" && ICAO != "\\N") {
                Node* n = new Node(stoi(idx), IATA, ICAO, stoi(lat), stoi(lon), alt_);
                graph.insert(std::make_pair(stoi(idx), n));
            }
        } catch (std::invalid_argument) { continue; }
    }
}

Graph::Graph(string file) {
    fstream datafile(file);
    while (datafile.is_open() && datafile.good()) {
        string idx, name, loc, country, IATA, ICAO, lat, lon, alt, temp;
        getline(datafile, idx, ',');     // index
        getline(datafile, name, ',');    // name
        getline(datafile, loc, ',');     // location
        getline(datafile, country, ','); // country
        getline(datafile, IATA, ',');    // country
        getline(datafile, ICAO, ',');    // country
        getline(datafile, lat, ',');     // latitude
        getline(datafile, lon, ',');     // longitude
        getline(datafile, alt, ',');     // altitude
        getline(datafile, temp, ',');    // timezone
        getline(datafile, temp, ',');    // Daylight savings time
        getline(datafile, temp, ',');    // Database timezone
        getline(datafile, temp, ',');    // type of station
        getline(datafile, temp);         // source

        try {
            int alt_ = isNbr(alt) ? stoi(alt) : -1;
            if (IATA != "\\N" && ICAO != "\\N") {
                Node* n = new Node(stoi(idx), IATA, ICAO, stoi(lat), stoi(lon), alt_);
                graph.insert(std::make_pair(stoi(idx), n));
            }
        } catch (std::invalid_argument) { continue; }
    }
}

bool Graph::isNbr(string nbr) {
    for (size_t i = 0; i < nbr.size(); i++)
        if (nbr[i] < '0' || nbr[i] > '9') return false;
    return true;
}

Node* Graph::getNode(int key) {
    return graph[key];
}

bool Graph::hasNode(int key) {
    return graph.contains(key);
}

void Graph::AddEdges() {
    string path = "routes.dat";
    fstream datafile(path);
    while (datafile.is_open() && datafile.good()) {
        string al, al_id, sap, sap_id, dap, dap_id, cs, stops, equip;
        getline(datafile, al, ',');
        getline(datafile, al_id, ',');
        getline(datafile, sap, ',');
        getline(datafile, sap_id, ',');
        getline(datafile, dap, ',');
        getline(datafile, dap_id, ',');
        getline(datafile, cs, ',');
        getline(datafile, stops, ',');
        getline(datafile, equip);

        if (isNbr(sap_id) && isNbr(dap_id))
            graph[stoi(sap_id)]->addAirport(graph[stoi(dap_id)], distance(graph[stoi(sap_id)], graph[stoi(dap_id)]));
    }
}

void Graph::AddEdges(string file) {
    fstream datafile(file);
    while (datafile.is_open() && datafile.good()) {
        string al, al_id, sap, sap_id, dap, dap_id, cs, stops, equip;
        getline(datafile, al, ',');
        getline(datafile, al_id, ',');
        getline(datafile, sap, ',');
        getline(datafile, sap_id, ',');
        getline(datafile, dap, ',');
        getline(datafile, dap_id, ',');
        getline(datafile, cs, ',');
        getline(datafile, stops, ',');
        getline(datafile, equip);
        if (isNbr(sap_id) && isNbr(dap_id))
            graph[stoi(sap_id)]->addAirport(graph[stoi(dap_id)], distance(graph[stoi(sap_id)], graph[stoi(dap_id)]));
    }
}

map <int, Node*>& Graph::getGraph() {
    return graph;
}

double Graph::BFS(int depart_id, int arrival_id) {
    // Mark all the vertices as not visited
    int curr_id = depart_id;
    map<int, bool> visited;
    // for (size_t i = 0; i < graph.size(); i++) visited.push_back(false);
 
    // Create a queue for BFS
    queue<pair<int, double>> q;
    pair<int, double> curr_front;
 
    // Mark the current node as visited and enqueue it
    visited[curr_id] = true;
    q.push(pair<int, double>(curr_id, 0));
    bool found = false;
 
    while(!q.empty() && !found)
    {
        // Dequeue a vertex from queue and print it
        curr_front = q.front();
        curr_id = curr_front.first;
        if (curr_id == arrival_id) return curr_front.second;
        q.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto neighbor: graph[curr_id]->neighbors)
        {
            if (!visited[neighbor.first->id_])
            {
                visited[neighbor.first->id_] = true;
                q.push(pair<int, double>(neighbor.first->id_, curr_front.second + neighbor.second));
            }
        }
    }

    return -1;
}

double Graph::Dijkstra(int depart_id, int arrival_id) {
    //airport, cumulative distance
    map<Node*, double> visited;

    //to visit queue
    queue<Node*> kyu;
    
    //push initial node onto kyu and mark as visited
    kyu.push(graph[depart_id]);
    visited.insert(make_pair(graph[depart_id], 0));

    while(kyu.size() != 0)
    {
        Node* cur = kyu.front();
        double cur_dist = visited[cur];
        kyu.pop();

        for(auto iter = cur->neighbors.begin(); iter != cur->neighbors.end(); iter++)
        {
            //if visited already and cur cumulative distance is less than previous distance or not visited at all then continue on path
            if((visited.find(iter->first) != visited.end() 
                &&  cur_dist + this->distance(cur,iter->first) < visited.find(iter->first)->second) || 
                (visited.find(iter->first) == visited.end()))
            {
                visited[iter->first] = cur_dist + this->distance(cur,iter->first);
                kyu.push(iter->first);
            }
        }
    } 
    //if destination not reached return -1 else return distance.
    if(visited.find(graph.find(arrival_id)->second) != visited.end()) 
        return visited.find(graph.find(arrival_id)->second)->second;
    else return -1;
}

double Graph::distance(Node *a1, Node *a2) {
    double lat1 = M_PI / 180 * a1->lat_;
    double long1 = M_PI / 180 * a1->long_;
    double lat2 = M_PI / 180 * a2->lat_;
    double long2 = M_PI / 180 * a2->long_;

    double ans = pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    double R = 3956;
    ans = ans * R;

    return ans;
}

double Graph::IDDFS(int depart_id, int arrival_id){
    for (size_t i = 0; i < graph.size(); i++)
    {
        double val = _IIDDFS(graph.find(depart_id)->second, arrival_id, i, 0);
        if(val != -1.0){
            return val;
        }
    }
    return -1.0;
}

double Graph::_RIDDFS(Node* cur, int arrival_id, int limit , double length)
{   
    if(cur == graph.find(arrival_id)->second) return length;

    if(limit <= 0) return -1.0;

    for(auto i = cur->neighbors.begin(); i != cur->neighbors.end(); i++)
    {
        double val = _RIDDFS(i->first, arrival_id, limit-1, length+distance(cur, i->first));
        if(val != -1) return val;
    }
    return -1;
}

double Graph::_IIDDFS(Node* start, int arrival_id, int lim, double len)
{   
    stack<pair<pair<Node*,double>, int>> nodes;
    nodes.push(make_pair(make_pair(start, len), lim)); 

    while(nodes.size() != 0)
    {
        Node* cur = nodes.top().first.first;
        double length = nodes.top().first.second;
        if(cur == graph.find(arrival_id)->second) return length;

        int limit = nodes.top().second;
        nodes.pop();
        for(auto i = cur->neighbors.begin(); i != cur->neighbors.end(); i++)
        {
            if(limit > 0) nodes.push(make_pair(make_pair(i->first, length+distance(cur, i->first)),limit-1));
        }
    }
    return -1.0;
}