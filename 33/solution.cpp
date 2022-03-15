class Solution {
public:
    // Tree is valid if all nodes are connected and there are no cycles. Additionally
    // it should have only one root that then connects to all other nodes
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size()) 
            return false;
        
        // Create an adjacency list to represent the graph
        std::vector<std::vector<int>> adj_list(n, std::vector<int>{});
        for (auto& edge : edges) {
            adj_list[edge.front()].push_back(edge.back());
            adj_list[edge.back()].push_back(edge.front());
        }
        
        // Do an iterative DFS to see if a cycle exists and if all nodes are connected
        vector<bool> seen(n, false);
        seen[0] = true;
        
        int count(1);
        stack<int> s;
        s.push(0);
        
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            
            for (auto neighbor : adj_list[current]) {
                if (seen[neighbor])
                    continue;
                
                seen[neighbor] = true;
                count++;
                s.push(neighbor);
            }
        }
        
        return count == n;
    }
};

#if 0

struct Node {
    int val;
    vector<Node*> neighbors;  
    
    Node(int val_) : val(val_), neighbors() {}
};

class Solution {
public:
    // Tree is valid if all nodes are connected and there are no cycles. Additionally
    // it should have only one root that then connects to all other nodes
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 1) return true;
        
        // For each number 0 to n - 1 create a node
        std::vector<Node*> nodes(n, nullptr);
        for (int i = 0; i < nodes.size(); ++i) {
            nodes[i] = new Node(i);
        }
        
        // Iterate the edges and build the tree. 
        for (auto& edge : edges) {
            nodes[edge.front()]->neighbors.push_back(nodes[edge.back()]);
            nodes[edge.back()]->neighbors.push_back(nodes[edge.front()]);
        }
        
        // If any node has no neighbors then we know that this is not a valid tree (i.e 
        // there is a disconnected node)
//         for (auto node : nodes) {
//             if (node->neighbors.empty()) {
//                 return false;
//             }
//         }
        
        // Check for a cycle
        unordered_set<Node*> path, allConnectedNodes;
        path.reserve(n);
        allConnectedNodes.reserve(n);
        if (checkForCycle(nodes[0], nullptr, path, allConnectedNodes)) {
            return false;
        }
        
        return allConnectedNodes.size() == n;
    }
    
    int countNodes(Node* node) {
        int count = 1;
        queue<Node*> q;
        q.push(node);
        unordered_set<Node*> visited;
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            if (visited.find(current) != visited.end())
                continue;
            
            visited.insert(current);
            
            for (auto neighbor : current->neighbors) {
                q.push(neighbor);
            }
        }
        
        return visited.size();
    }
    
    bool checkForCycle(Node* node, const Node* parent, unordered_set<Node*>& path, unordered_set<Node*>& allNodes) {
        if (node == nullptr) 
            return false;
        
        if (path.find(node) != path.end()) {
            return true;
        }
        
        path.insert(node);
        allNodes.insert(node);
        
        for (auto child : node->neighbors) {
            if (path.find(child) == path.end()) {
                if (checkForCycle(child, node, path, allNodes)) {
                    return true;
                }
            }
            else if (child != parent) {
                return true;
            }
        }
        path.erase(node);
        
        return false;    
        
    }
};

#endif
