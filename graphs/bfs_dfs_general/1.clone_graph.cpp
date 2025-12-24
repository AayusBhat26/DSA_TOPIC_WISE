#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    // each node wouild have negihbours vector and value
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        unordered_map<Node *, Node *> graph;

        graph[node] = new Node(node->val);
        queue<Node *> q;
        q.push(node); // given graph is being pushed
        while (!q.empty())
        {
            // in first iteration i got the given graph's node
            Node *currentNode = q.front();
            q.pop();

            // visiting and building neigbours, i will have the neigbours to the given graph's node
            for (Node *neig : currentNode->neighbors)
            {
                if (graph.find(neig) == graph.end())
                {
                    graph[neig] = new Node(neig->val);
                    q.push(neig); // this neigbour is from the given graph
                }
                // currentNode's neigbours would be added with the neighbour of newly created neigbours
                graph[currentNode]->neighbors.push_back(graph[neig]);
            }
        }

        return graph[node];
    }
};