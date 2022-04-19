#pragma once

#include <map>
#include <string>

using namespace std;

class Node {
    //data variables
    private:
        
    public:
        int id_;
        string IATA_;
        string ICAO_;
        double lat_;
        double long_;
        int alt_;
        map<Node*, double> neighbors;

        Node();
        Node(int id, /*string name, string city, string country,*/ string IATA, string ICAO, double lat, double longi, int alt);

        void addAirport(Node* a, double d);
};