## Week of 03/27 - 04/03
### Goals: 
Our goals for this week was to create a node class that would hold the relevant data for each airport. We also wanted to get started witha the data procssing so that we could read in the data from the airport.dat dataset in a useable manner (into Nodes).

### Progress:

**Nihal:** Created a rudimentary Node Class to hold airport data.

**Manan:** Started looking into Dijkstra's Algorithm and Iterative Deepening to better understand how they work.

**Arul:** Looked into how to access csv files using C++.

### Problems: 
We were all very busy this week due to midterms so ost of our time was spent researching rather than coding.

### Next Weeks Plans:
We hope to finish the Node class and start working on a way to link the Nodes together. We also hope to be done with a method to read data in form a CSV file.


## Week of 04/03 - 04/10

### Goals: 
Our goals for this week was to create our Graph Class that would store all our nodes by reading from the airport.dat file. We also looked into how we would create our traversals using the created Node and Graph Classes.

### Progress:

**Nihal:** This week, I unfortunately was hit with COVID-19, and I had to spend the majority of the week recovering and tending to my own health. However, I was still able to make some progress on the Dijstra algorithm and gained a stronger conceptual understanding of what this algorithm requires from us. I started coding it, but I was not yet able to produce enough to push to the GitHub. My hope is to finish up the algorithm by next Sunday, April 17th.

**Manan:** Finished the Node class to include complete set of data we deemed relevant. Also included a map of Nodes to distances to keep track of connected airports and the distance of route.

**Arul:** Created Graph Class and added file reading functionality to read from airports.dat.

### Problems: 
Unfortunatly, the majority of our group was hit with midterms this week, and with Nihal in quarantine housing for the entire week due to COVID, most of our time had to be spent researching instead of coding.
### Next Weeks Plans:
We hope to add in functionality to create edges into our Graph class and to try to implement a simple BFS on our created graphs.

## Week of 04/10 - 04/17
### Goals: 
Our goals for this week was to finish our graph class, implement a traversal using our previous research, and to test our code by making test cases and a makefile and then running our code.

### Progress:

This week, all three of us met up to work together on the code. We liveshared the code on Manan's computer and worked on finishing the Graph Class, the makefile, and the test cases. We were able to finish an implementation of the Dijkstra that we were able to test rudimentarily on online compilers. However, when we tried to test locally on our locally created test cases, we ran into problems since we didn't have experience making a Makefile.

### Problems: 
We implemented a Dijkstra algorithm rather than a BFS since we were not sure how to create a BFS that would work on a weighted graph and how the algorithm would differ from a Dijkstra's algorithm. We also were not able to create a Makefile sepite working on it all weekend so we were not able to test our code locally with our test cases (and thus cannot validate whether our code is correct).

### Next Weeks Plans:
We hope to be done with our Makefile and to have implemented our BFS traversal code. We also hope to fully debug any issues our Dijkstra may have (unknown at the moment since we weren't able to extensively test) and to test edge cases with our test cases. We hope to make our test cases more robust and to have the test cases all our functions.

## Week of 04/17 - 04/24
### Goals: 
Our goals for this week was to get our makefie running and to create test cases for our code.

### Progress:

This week, all three of us met up to work together on the code. We liveshared the code on Nihal's computer and worked on gettingt he Makefile to work. We finished the makefile and then transitioned to testing our code where we ran into issues getting our Graph class to read file input in the test cases, while it still worked in the main. We eventually figured out it was a file pathing issue and were able to resolve it and test all our code.

### Problems: 
We ran into issues with the makefile which we were able to resolve and also ran into issues with file pathing and how file reads work with different file paths. Currently we have no issues in our code progress.

### Next Weeks Plans:
We hope to be done with our BFS algorithm and to start working on our Iterative Deepening DFS algorithm. We also hope to get a basic terminal interaction set up so that the user can interact with our Graph Class in a significant way and can enter two airports to find the shortest path between. We also hope to continue to make our test cases more robust.
