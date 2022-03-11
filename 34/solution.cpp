class Solution {
public:
    // Create a set of graphs from the edges. Find the set of nodes which have no inbound edges and 
    // BFS. During BFS we paint all found nodes - if we discover a painted node then we do not 
    // increment our component count. Otherwise we do
    int countComponents(int n, vector<vector<int>>& edges) {
        
        if (n == 0 || edges.empty()) 
            return n;
        
        // Create an adjacency list for each node and populate the edges
        std::vector<vector<int>> adjacencyLists(n, std::vector<int>{});
        for (auto& edge : edges) {
            adjacencyLists[edge.front()].push_back(edge.back());
            adjacencyLists[edge.back()].push_back(edge.front());
        }
        
        // We'll keep track of nodes we've already discovered and mark them off to ensure that we don't
        // double count a sub graph
        vector<int> discoveredNodes(n, 0);
        
        int components(0);
        for (int i = 0; i < adjacencyLists.size(); ++i) {
            // Short circuit to not search if we've already seen this node
            if (discoveredNodes[i] != 0)
                continue;
            
            // It hasn't been discovered yet so it's definitely a new component
            components++;
            dfs(i, adjacencyLists, discoveredNodes);
        }
        return components;
    }
    
    void dfs(int node, const vector<vector<int>>& adjacencyLists, vector<int>& discoveredNodes) {
        // This is a new component for sure since the node has no edges
        if (adjacencyLists[node].empty()) {
            return;
        }
        
        discoveredNodes[node] = 1;
        
        // This node has at least one edge - we'll DFS to see if we encounter any other nodes that
        // may have already been accounted for
        for (auto adjNode : adjacencyLists[node]) {
            if (discoveredNodes[adjNode] == 0) 
                dfs(adjNode, adjacencyLists, discoveredNodes);   
        }
    }
    
};

#if 0
struct Node {
    int val;
    vector<Node*> neighbors;
    
    Node(int val_) : val(val_) {}
};

class Solution {
public:
    // Create a set of graphs from the edges. Find the set of nodes which have no inbound edges and 
    // BFS. During BFS we paint all found nodes - if we discover a painted node then we do not 
    // increment our component count. Otherwise we do
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, Node*> nodes;
        for (auto edge : edges) {
            if (nodes.find(edge.front()) == nodes.end())
                nodes[edge.front()] = new Node(edge.front());
            
            if (nodes.find(edge.back()) == nodes.end())
                nodes[edge.back()] = new Node(edge.back());
            
            nodes[edge.front()]->neighbors.push_back(nodes[edge.back()]);
            nodes[edge.back()]->neighbors.push_back(nodes[edge.front()]);
        }
        
        int components = 0;
        unordered_set<Node*> previousNodes;
        for (auto node : nodes) {
            components += bfsNodes(node.second, previousNodes);
        }
        
        // Capture all the nodes that had no edges (e.g. n - nodes.size())
        return n - nodes.size() + components;
    }
    
    
    int bfsNodes(Node* start, unordered_set<Node*>& previouslyFoundNodes) {
        int result = 1;
        
        queue<Node*> q;
        q.push(start);
        
        unordered_set<Node*> currentNodes;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if (currentNodes.find(node) != currentNodes.end()) {
                continue;
            }
            
            currentNodes.insert(node);
            
            if (previouslyFoundNodes.find(node) != previouslyFoundNodes.end()) {
                return 0;
            }
            
            previouslyFoundNodes.insert(node);   
            
            for (auto neighbor : node->neighbors) {
                if (currentNodes.find(neighbor) == currentNodes.end()) 
                    q.push(neighbor);
            }          
            
        }
        return 1;
    }
};
#endif
