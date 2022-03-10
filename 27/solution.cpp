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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        
        unordered_map<Node*, Node*> clonedNodes;
        
        queue<Node*> nodeQueue;
        nodeQueue.push(node);
        clonedNodes[node] = new Node(node->val);
        
        while (!nodeQueue.empty()) {
            auto currentNode = nodeQueue.front();
            auto cloneNode = clonedNodes[currentNode];
            
            for (auto neighbor : currentNode->neighbors) {
                Node* clonedNeighbor = nullptr;
                auto findIt = clonedNodes.find(neighbor); 
                if (findIt == clonedNodes.end()) {
                    clonedNeighbor =  clonedNodes[neighbor] = new Node(neighbor->val);
                    nodeQueue.push(neighbor);
                } else {
                    clonedNeighbor = findIt->second;
                }
                
                cloneNode->neighbors.push_back(clonedNeighbor);
            }
            
            nodeQueue.pop();
        }
        
        return clonedNodes[node];
        
    }
};
