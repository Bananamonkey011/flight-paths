#include "Node.h"

Node::Node() {
    id_ = 0;
    // name_ = "";
    // city_ = "";
    // country_ = "";
    IATA_ = "";
    ICAO_ = "";
    lat_ = 0;
    long_ = 0;
    alt_ = 0;
}

Node::Node(int id, /*string name, string city, string country,*/ string IATA, string ICAO, double lat, double longi, int alt){
    id_ = id;
    // name_ = name;
    // city_ = city;
    // country_ = country;
    IATA_ = IATA;
    ICAO_ = ICAO;
    lat_ = lat;
    long_ = longi;
    alt_ = alt;
}

void Node::addAirport(Node* a, double d){
    airports_[a] = d;
}
