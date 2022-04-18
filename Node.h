#pragma once

#include <map>
#include <string>

using namespace std;

class Node {
    //data variables
    private:
        int id_;
        // string name_;
        // string city_;
        // string country_;
        string IATA_;
        string ICAO_;
        double lat_;
        double long_;
        int alt_;
        map<Node*, double> neighbors;
        
        //idt we need more than these
    public:
        //map of connecting airports and the route distance

        Node();
        Node(int id, /*string name, string city, string country,*/ string IATA, string ICAO, double lat, double longi, int alt);

        void addAirport(Node* a, double d);
};