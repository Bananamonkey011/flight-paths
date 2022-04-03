# **Final Project - Nihal S, Arul V, Manan J**

## **Leading Question:**
Given a dataset of airports and their distances from each other, as well as the flights taken in between airports, can we produce an algorithm that takes in a user's current airport and their desired destination to determine the shortest path they have to take? We plan to use the publicly accesible datasets airports.dat and routes.dat from OpenFlights. airports.dat conatins a list of all the airport terminals that we hope to use as the nodes in our graph. routes.dat contains all possible edeges in our graph in the sense of plane routes from one airport to another. We hope to learn traversal algorithms and graph theory by implementing graph traversal algorithms on a graph made of airports as nodes. We plan to experiment with 3 different shortest-path finding algorithms to see which will return the shortest path in the fastest amount of time. These algorithms will be Breath First Search, a Dijkstra path algorithm, and an Iterative Deepening Depth First Search.

## **Dataset Acquisition and Processing:**
#### Data Format
The datasets we are using are from OpenFlights. The first dataset is aiports.dat which contains over 10,000 airports, train stations, ferry stations, and other transportation centers. The second dataset is routes.dat which has 67663 routes between 3321 airports on 548 airlines spanning the globe which we will use to create edges between our graph nodes. The data is stored as a CSV file. We plan to only use the airport subset of the OpenFlights dataset containing airport locations to augment the creation of our graph of flights and their start port to end port using the second dataset indicated. This way we can create a graph that spans across the globe and maps out all the paths of airport travel. We also plan to use the geographic distance of a route as the distance metric for our edges.
#### Data Correction
We will parse the data by reading line by line and separating values at each comma. We know exactly which data is in what column so we simply need to format our code to categorize data based on that. We will check if our data is error free by crossreferencing outlier data points with distance calculated using the longitude and latitude positions given within the first dataset. We will check for missing entries by looking for data points with just spaces, special characters, and/or no value stored. If a data point has incomplete data, it will be ignored and will not be used due to our inability to correct the data ourselves and its unreliability as a datapoint. 

#### Data Storage
We will store our data using a graph. We will store each airport as a node within our graph and create edges between airports that have a flight connection. We expected the data storage to be O(N+M) where N is the number of airports and M is the number of flights. 

## **Graph Algorithms:**
We will use a Breath First Search, a Dijkstra path algorithm, and an Iterative Deepening Depth First Search.

#### Function Inputs
The expected inputs for all three algorithms are a starting airport node and the destination airport node. 

For the algorithms, we will have to convert the airports into nodes and the flights into edges. We will do this by converting each airport into a node containing it's latitudinal and longitudinal position. We will then create edges between flights. Edges will be weighted on the number of flights with a minimal number of stops and redirects between the two airports. Finally, lengths of the flight path will be calculated by finding the shortest path and finding the distance by using latitude and longitudes given in the first dataset.

#### Function Outputs
The function output will be an integer that will contain the shortest distance from the starting airport to the destination airport, which we will return to the user.

#### Function Efficiency
N is the number of airports and M is the number of edges. 

Our Breath First Search will be O(N) in both memory and in runtime as it will have a queue to store the nodes we are currently visiting and the worst case is that one airport has flights to all other airports hence being O(N). The runtime will also be O(N) since we will only traverse to nodes we have not visited before and hus in the worst case will visit every airport atleast once.

Our Dijkstra algorithm will be O(N^2) in runtime and O(M) in memory as we will be using a priority queue to implement our algorithm and the worst case is that one airport has flights to every other airport hence being O(M) in memory.

Our Iterative Deeping Depth First Search will be O(B^D) in runtime, where B is the branching factor and D is the depth of the goal. In memory, our algorithm will be O(D).

## **Timeline:**
- Week 1: Acquire and clean data to create final project csv file for both airports and flights.
- Week 2: Reading about Dijkstra's shortest path algorithm and Iterative Deepening Depth First Search. We will also implement the creation of the graph code.
- Week 3: Creating our BFS and finishing the implementation of the creation of the graph code as well as preliminary testing.
- Week 4: Creating our Dijkstra algorithm and our Iterative Deepening DFS algorithm.
- Week 5: Finishing the creation of our Dijkstra and Iterative Deepening DFS algorithm and putting it all together.
- Week 6: Final testing and creation of project research paper.
