# **Final Project - Nihal S, Arul V, Manan J**

## **Leading Question:**
Given a dataset of airports and their distances from each other, as well as the flights taken in between airports, can we produce an algorithm that takes in a user's current airport and their desired destination to determine the shortest path they have to take? We hope to learn traversal algorithms and graph theory from the implementation of graph traversal algorithms on a graph made of airports as nodes.

## **Dataset Acquisition and Processing:**
#### Data Format
The dataset we are using is OpenFlights which contains over 10,000 airports, train stations, ferry stations, and other transportation centers. The second dataset we are using has 67663 routes between 3321 airports on 548 airlines spanning the globe which we will use to create edges between our graph nodes. The data is stored as a csv file. We plan to only use the airport subset of the OpenFlights dataset containing port locations to augment the creation of our graph of flights and their start port to end port using the second dataset indicated. This way we can create a graph that spans across the globe and maps out all the paths of airport travel.
#### Data Correction
We will parse the data by reading line by line and separating values at each comma. We know exactly which data is in what column so we simply need to format our code to categorize data based on that. We will check if our data is error free by crossreferencing outlier data points with distance calculated using the longitude and latitude positions given within the first dataset. We will check for missing entries by looking for data points with just spaces, special characters, and/or no value stored. If a data point has incomplete data, it will be ignored and will not be used due to our inability to correct the data ourselves and its unreliability as a datapoint. 

#### Data Storage
We will store our data using a graph. We will store each airport as a node within our graph and create edges between airports that have a flight connection. We expected the data storage to be O(N+M) where N is the number of airports and M is the number of flights. 

## **Graph Algorithms:**
We will use a Breath First Search, a Dijkstra path algorithm, and a Delta Stepping SSSP algorithm.

#### Function Inputs
The expected inputs for all three algorithms are a starting airport node and the destination airport node. 

For the algorithms, we will have to convert the airports into nodes and the flights into edges. We will do this by converting each airport into a node containing it's latitudinal and longitudinal position. We will then create edges between flights. Edges will be weighted on the number of flights with a minimal number of stops and redirects between the two airports. Finally, lengths of the flight path will be calculated by finding the shortest path and finding the distance by using latitude and longitudes given in the first dataset.

#### Function Outputs
The function output will be an integer that will contain the shortest distance from the starting airport to the destination airport. 

#### Function Efficiency
blah blah blah

## **Timeline:**
1. blah
2. blah
3. blah
