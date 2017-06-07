# -*- coding: utf-8 -*-
"""
Created on Tue May 23 11:44:02 2017

@author: HSINGH
"""
class Graph:
    """
      Read the Intialized Graph and Create a Adjacency list out of it 
	   There could be cases where in the initialized graph <map> link
      issues are not maintained
	   for example node 2 to 1 link 
	    2->1
	   there needs to be a link then since undirected Graph
	    1->2
    """
    
    def __init__(self,Graph_init):
        self.edge={}
        for keys,values in Graph_init.items():
             for value in values:
                 self.addEdge(keys,value);
      
    """
    Add a vertex to graph map
	structure is
	int => int list
    """
    def addVertex(self,v):
        if v not in self.edge:
            self.edge[v]=[]
    """
	Add Edge from both vertex to each other
	Make sure the nodes are present   
   """      
    def addEdge(self,u,v):
        if u not in self.edge:
            self.addVertex(u)
        if v not in self.edge:
            self.addVertex(v)
        if u not in self.edge[v]:
            self.edge[v].append(u)
        if v not in self.edge[u]:
            self.edge[u].append(v)
            
    def isEdge(self,u,v):
        if u not in self.edge:
            return False
        if v not in self.edge:
            return False 
        return  u in self.edge[v] 
    
    def display(self):
        for keys,values in self.edge.items():
            print(keys,":=>",values)

"""A initalized Graph (not in form of adjaceny list"""
Graph_init = {1:[2,3,5],
              2:[1,4],
              3:[1,6]};
              
"""Default constrcutor takes care of making the initialzed map to adjaceny list"""                 
g=Graph(Graph_init)
g.addVertex(1)
g.addVertex(2) 
g.addVertex(3)
g.addEdge(1,2)
g.addEdge(3,2)
g.display();
         

              
              
            
            
            
        