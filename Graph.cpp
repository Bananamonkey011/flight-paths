#include "Graph.h"
#include <sstream>
#include <fstream>
#include <filesystem>
#include <string>
#include <iostream>

using namespace std;

Graph::Graph(std::string file)
{
    string datapath = "airports.dat";
    fstream datafile(datapath);
    while(datafile.is_open() && datafile.good())
    {
        string idx, name, loc, country, IATA, ICAO, lat, lon, alt, temp;
        getline(datafile, idx, ',');   //index
        getline(datafile, name, ',');   // name
        getline(datafile, loc, ',');    // location
        getline(datafile, country, ','); //country
        getline(datafile, IATA, ','); //country
        getline(datafile, ICAO, ','); //country
        getline(datafile, lat, ',');    // latitude
        getline(datafile, lon, ',');    // longitude
        getline(datafile, alt, ',');   // altitude
        getline(datafile, temp, ',');   // timezone
        getline(datafile, temp, ',');   // Daylight savings time
        getline(datafile, temp, ',');   // Database timezone
        getline(datafile, temp, ',');        // type of station
        getline(datafile, temp);        // source

        // create node using given information
        Node n = Node(stoi(idx), IATA, ICAO, stoi(lat), stoi(lon), stoi(alt));
        points.insert(std::make_pair(stoi(idx), n));
    }

}

void Graph::AddEdges(std::string file){
    string path = "routes.dat";
    fstream datafile(path);
    while(datafile.is_open() && datafile.good())
    {
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

        this->points.find(stoi(sap_id));
        
    }
}