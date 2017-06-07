# -*- coding: utf-8 -*-
"""
Created on Tue May 23 11:44:02 2017

@author: HSINGH
"""
class Graph:
    def __init__(self):
        self.edge={}
        
    def addVertex(self,v):
        if v not in self.edge:
            self.edge[v]=[]
            
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
            
            
            
        