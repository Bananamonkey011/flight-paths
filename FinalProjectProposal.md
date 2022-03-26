# **Final Project - Nihal S, Arul V, Manan J**

## **Leading Question:**
Given a dataset of airports and their distances from each other, as well as the flights taken in between airports, can we produce an algorithm to determine the shortest path between any two airports. We hope to learn traversal algorithms and graph theory from the implementation of graph traversal algorithms on a graph made of airports as nodes.

## **Dataset Acquisition and Processing:**
#### Data Format
The dataset we are using is OpenFlights which contains over 10,000 airports, train stations, ferry stations, and other transportation centers. The second dataset we are using has 67663 routes between 3321 airports on 548 airlines spanning the globe which we will use to create edges between our graph nodes. The data is stored as a csv file. We plan to only use the airport subset of the OpenFlights dataset containing port locations to augment the creation of our graph of flights and their start port to end port using the second dataset indicated. This way we can create a graph that spans across the globe and maps out all the paths of airport travel.
#### Data Correction
We will parse the data by reading line by line and separating values at each comma. We know exactly which data is in what column so we simply need to format our code to categorize data based on that. We will check if our data is error free 

We will check for missing entries by looking for data points with just spaces and no value stored. If a data point has incomplete data, it will be ignored and will not be used due to our inability to correct the data ourselves and its unreliability as a datapoint. 
#### Data Storage
blah blah blah

## **Graph Algorithms:**

#### Function Inputs
blah blah blah

#### Function Outputs
blah blah blah

#### Function Efficiency
blah blah blah

## **Timeline:**
1. blah
2. blah
3. blah
