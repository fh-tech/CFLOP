/////// get existing node
```json
{
  "nodes": {
    "get": {
      "id": 0
    }
  }
}
```
-->
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

```json
{
  "error": {
    "message": "some fail message"
  }
}
```




/////// create node
```json
{
  "nodes": {
    "post": {}
  }
}
```

-->
```json
{
  "success": {
    "node": { "id": 0 }
  }
}
```
///////delete node
```json
{
  "nodes": {
    "delete": {
      "id": 0
    }
  }
}
```
-->
```json
{
  "success": {}
}
```

////// make start node
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
-->
```json
{
  "success": {}
}
```

////// make end node
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
-->
```json
{
  "success": {}
}
```

//////get edge
```json
{
  "edges": {
    "get": {
      "id": 0
    }
  }
}
```
-->
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
```
////// create new edge
```json
{
  "edges":{
    "post":{
      "id": 0,
      "to": 1,
      "from": 2
    }
  }
}
```
-->
```json
{
  "success":{}
}
```
//////// delte edge
```json
{
  "edges": {
    "delete": {
      "id": 0
    }
  }
}
```
-->
```json
{
  "success":{}
}
```

/////// STATE get
```json
{
  "state":{
    "get":{}
  }
}
```
-->
```json
{
  "success":{
    "state":{
      "nodes": [
        {
          "id": 0,
          "connectedNodes": [1,2,3]
        }, {
          "id": 1,
          "connectedNodes": [1,3]
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

//// load state
```json
{
  "state":{
    "post":{
      "state": {
        "nodes": [
          {
            "id": 0,
            "connectedNodes": [1,2,3]
          }, {
            "id": 1,
            "connectedNodes": [1,3]
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
-->
```json
{
  "success": {}
}
```