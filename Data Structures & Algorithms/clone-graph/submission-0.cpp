/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs (Node* node , unordered_map<Node* , Node*>& m)
{
    if (node == NULL)   return NULL ;

    Node* copy ;
    if (m.find (node) != m.end ())  return m[node];
    else    
    {
        copy = new Node (node -> val) ;
        m[node] = copy ;
    }

    for (Node* n : node -> neighbors)
    {
        Node* cloneNeighbor = dfs (n , m) ;
        copy -> neighbors.push_back (cloneNeighbor) ;
    }

    return copy ;
}

Node* cloneGraph (Node* node)
{
    unordered_map<Node* , Node*> m ;

    return dfs (node , m) ;
}
};
