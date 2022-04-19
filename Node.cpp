#include "Node.h"

Node::Node() {
    IATA_ = "";
    ICAO_ = "";
    lat_ = 0;
    long_ = 0;
    alt_ = 0;
}

Node::Node(int id, string IATA, string ICAO, double lat, double longi, int alt) {
    IATA_ = IATA;
    ICAO_ = ICAO;
    lat_ = lat;
    long_ = longi;
    alt_ = alt;
}

void Node::addAirport(Node* a, double d) { if(neighbors.find(a) == neighbors.end()) neighbors[a] = d; }