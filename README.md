# CFLOP
##Finite State Machine Simulation

### Communication between back- and frontend via JSON (HTTP-Style)

#### 1. Endpoints  
##### 1.1 NODES
* POST  
    * adds a new node to the graph
* DELETE  
    * deletes node with given ID from the graph
* GET  
    * gets the node object with the given ID 
* PUT/START  
    * sets the node with the given ID as starting point
* PUT/END
    * sets the node with the given ID as end point
    
####1.2 EDGES  
* GET
    * gets the edge object with the given ID  
* POST  
    * adds an edge between the two given nodes (IDs)
* DELETE  
    * deletes node with the given ID

####1.3 STATE
* GET
    * gets the current state of the graph (all nodes, all edges, start, end, active) (save)
* POST
    * sets the state of the graph (load)  
* PUT  
    * takes a given transition and executes a step in the graph with it
    

