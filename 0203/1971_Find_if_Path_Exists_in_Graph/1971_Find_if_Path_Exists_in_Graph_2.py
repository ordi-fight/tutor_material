from typing import List
class Node:
  
  def __init__(self,id,neighbors:list):
    
    self.id = id
    self.neighbors = neighbors
    self.visited = False
  
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        
        nodes = []
        
        for N in range(n):
          
          nodes.append(Node(N,[]))
          
        for edge in edges:
          
          (nodes[edge[0]].neighbors).append(nodes[edge[1]])
          (nodes[edge[1]].neighbors).append(nodes[edge[0]])
        
        def recur(node):
          
          if node.id == destination:
            
            return True
          if node.visited == True:
            return False
          # handle choices
          node.visited = True
          for nei in node.neighbors:
            
            if recur(nei):
              
              return True
          return False
          
        return recur(nodes[source])