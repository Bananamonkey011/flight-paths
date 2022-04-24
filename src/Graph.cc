#include "Graph.h"
#include <queue>
#include <iostream>
using namespace std;

Graph::Graph() { // TODO(): HANDLE INCORRECT DATA
    string datapath = "airports.dat";
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
        Node *n = new Node(stoi(idx), IATA, ICAO, stoi(lat), stoi(lon), stoi(alt));
        graph.insert(std::make_pair(stoi(idx), n));
    }
}

Graph::Graph(string file) {
    string datapath = file;
    fstream datafile(datapath);
    // cout << "hello" << endl;
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
        // cout << idx << endl;
        // cout << name << endl;
        // cout << loc << endl;
        // cout << country << endl;
        // cout << IATA << endl;
        // cout << ICAO << endl;
        // cout << lat << endl;
        // cout << lon << endl;
        // cout << alt << endl;
        // cout << temp << endl;
        // create node using given information
        // cout << "hi" << endl;
        Node* n = new Node(stoi(idx), IATA, ICAO, stoi(lat), stoi(lon), stoi(alt));
        graph.insert(std::make_pair(stoi(idx), n));
    }
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
        graph[stoi(sap_id)]->addAirport(graph[stoi(dap_id)], distance(graph[stoi(sap_id)], graph[stoi(dap_id)]));
    }
}

void Graph::AddEdges(string file) {
    string path = file;
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
        graph[stoi(sap_id)]->addAirport(graph[stoi(dap_id)], distance(graph[stoi(sap_id)], graph[stoi(dap_id)]));
    }
}

map <int, Node*>& Graph::getGraph() {
    return graph;
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
