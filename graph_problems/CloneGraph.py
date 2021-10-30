"""Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors."""


import copy
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        return copy.deepcopy(node)
    