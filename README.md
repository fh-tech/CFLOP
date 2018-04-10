# CFLOP
##Finite State Machine Simulation

### Communication between back- and frontend via JSON (HTTP-Style)

#### 1. Endpoints  
##### 1.1 NODES
* POST  
    * adds a new node to the graph
    * request
    ```json
      {
        "nodes": {
          "post": {}
        }
      }
    ```
    * response
    ```json
    {
      "success": {
        "node": { "id": 0 }
      }
    }
    ```
* DELETE  
    * deletes node with given ID from the graph
    * request
    ```json
    {
      "nodes": {
        "delete": {
          "id": 0
        }
      }
    }
    ```
    * response 
    ```json
    {
      "success": {}
    }
    ```
    
* GET  
    * gets the node object with the given ID  
    * request  
    ```json
      {
        "nodes": {
          "get": {
            "id": 0
          }
        }
      }
    ```  
    * response (success)
      
    ```json
    {
      "success": {
        "node":{
          "id": 0,
          "edges": [1,2,3]
        }
      }
    }
    ``` 
* PUT/START  
    * sets the node with the given ID as starting point
    * request
    ```json
    {
      "nodes":{
        "put":{
          "start":{
            "id": 0
          }
        }
      }
    }
    ```
    * response
    ```json
    {
      "success": {}
    }
    ```
* PUT/END
    * sets the node with the given ID as end point
    * request
    ```json
    {
      "nodes":{
        "put":{
          "end":{
            "id": 0
          }
        }
      }
    }
    ```
    * response
    ```json
    {
      "success": {}
    }
    ```
    
    
#### 1.2 EDGES  
* GET
    * gets the edge object with the given ID  
    * request
    ```json
    {
      "edges": {
        "get": {
          "id": 0
        }
      }
    }
    ```
    * response
    ```json
    {
      "success": {
        "edge": {
          "id": 0,
          "from": 1,
          "to": 2,
        }
      }
    }
* POST  
    * adds an edge between the two given nodes (IDs)
    * request
    ```json
    {
      "edges":{
        "post":{
          "to": 1,
          "from": 2
        }
      }
    }
    ```
    * response
     ```json
        {
          "success": {
            "node": { "id": 0 }
          }
        }
     ```
* DELETE  
    * deletes node with the given ID
    * request
    ```json
    {
      "edges": {
        "delete": {
          "id": 0
        }
      }
    }
    ```
    * response
    ```json
    {
      "success":{}
    }
    ```

####1.3 STATE
* GET
    * gets the current state of the graph (all nodes, all edges, start, end, active) (save)
    * request
    ```json
    {
      "state":{
        "get":{}
      }
    }
    ```
    * response
    ```json
    {
      "success":{
        "state":{
          "nodes": [
            {
              "id": 0,
              "edges": [1,2,3]
            }, {
              "id": 1,
              "edges": [1,3]
            }
          ],
          "edges":[
            {
              "id": 1,
              "from": 0,
              "to": 1,
            }
          ],
          "active": 1,
          "start": 1,
          "end": 0
        }
      }
    }
    ```
* POST
    * sets the state of the graph (load) 
    * request
    ```json
    {
      "state":{
        "post":{
          "state": {
            "nodes": [
              {
                "id": 0,
                "edges": [1,2,3]
              }, {
                "id": 1,
                "edges": [1,3]
              }
            ],
            "edges":[
              {
                "id": 1,
                "from": 0,
                "to": 1,
              }
            ],
            "active": 1,
            "start": 1,
            "end": 0
          }
        }
      }
    }
    ```
    * response
    ```json
    {
      "success": {}
    }
    ```
     
* PUT  
    * takes a given transition and executes a step in the graph with it
    * request  
    ```json
    {
      "state": {
        "put": {
          "input": "a"
        }
      }
    }
    ```
    * response  
    ```json
    {
      "success": {
        "node": {"id": 0}
      } 
    }
  
    ```
    
    
####1.4 failed request
for every call that fails you get following response with a message  
```json
    {
      "error": {
        "message": "some fail message"
      }
    }
```
