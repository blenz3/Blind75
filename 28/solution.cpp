struct Node {
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = -1;
    }
    
    Node(int val_) : val(val_) {}
};

class Solution {
public:
    // Build a directed graph for each of the pre-requisites and DFS from each node to determine if 
    // any cycles exist
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create nodes for each course and link the edges in a directed fashion 
        // such that the first nodes are those with no prerequisites
        unordered_map<int, Node*> nodes;        
        for (auto prereq : prerequisites) {
            if (nodes.find(prereq.front()) == nodes.end()) 
                nodes[prereq.front()] = new Node(prereq.front());
            
            if (nodes.find(prereq.back()) == nodes.end()) 
                nodes[prereq.back()] = new Node(prereq.back());
            
            nodes[prereq.back()]->neighbors.push_back(nodes[prereq.front()]);
        }
        
        unordered_set<Node*> visited, checked;
        for (auto node : nodes) {
            if (containsCycle(node.second, visited, checked))
                return false;
        }
        
        return true;
    }
    
    bool containsCycle(Node* node, unordered_set<Node*>& visited, unordered_set<Node*>& checked) {
        if (node == nullptr) {
            return false;
        }
        
        if (visited.find(node) != visited.end()) {
            return true;
        }
        
        if (checked.find(node) != checked.end()) {
            return false;
        }
        
        visited.insert(node);
        checked.insert(node);
        
        for (auto neighbor : node->neighbors) {
            if (containsCycle(neighbor, visited, checked)) {
                return true;
            }
        }
        
        visited.erase(node);
        return false;
    }
};
