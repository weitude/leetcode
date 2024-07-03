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

class Solution
{
  public:
    Node *map[101];

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        dfs(node);
        return map[1];
    }

    void dfs(Node *node)
    {
        map[node->val] = new Node(node->val);

        for (auto neigh : node->neighbors)
        {
            if (!map[neigh->val])
                dfs(neigh);
            map[node->val]->neighbors.push_back(map[neigh->val]);
        }
    }
};
