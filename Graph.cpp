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
        string idx, name, loc, country, IATA, ICAO, lat, lon, temp;
        getline(datafile, idx, ',');   //index
        getline(datafile, name, ',');   // name
        getline(datafile, loc, ',');    // location
        getline(datafile, country, ','); //country
        getline(datafile, lat, ',');    // latitude
        getline(datafile, lon, ',');    // longitude
        getline(datafile, temp, ',');   // altitude
        getline(datafile, temp, ',');   // timezone
        getline(datafile, temp, ',');   // Daylight savings time
        getline(datafile, temp, ',');   // Database timezone
        getline(datafile, temp, ',');        // type of station
        getline(datafile, temp);        // source


        // create node using given information
    }

}

void Graph::AddEdges(std::string file){
    
}