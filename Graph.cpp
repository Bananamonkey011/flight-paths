#include "Graph.h"

using namespace std;

Graph::Graph(std::string file) {
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

void Graph::AddEdges(std::string file) {
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

vector<Node *> Graph::Dijkstra(int depart_id, int arrival_id) {
    vector<Node*> out;
    map<Node*, double> visited;

    Node* departure = graph[depart_id];
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
    double R = 6371;
    ans = ans * 6371;
}