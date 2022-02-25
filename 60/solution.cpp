/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Traverse the tree and maintain the depth. Find the max depth and bubble it back up
    int maxDepth(TreeNode* root) {
        return maxDepthIt(root);
#if 0
        int max = 0;
        maxDepthRec(root, 0, max);
        return max;
#endif
    }
    
private:
    void maxDepthRec(TreeNode* root, int currentDepth, int& maxDepth) {
        if (root == nullptr) {
            return;
        }
        
        maxDepth = std::max(++currentDepth, maxDepth);
        maxDepthRec(root->left, currentDepth, maxDepth);
        maxDepthRec(root->right, currentDepth, maxDepth);
    }
    
    int maxDepthIt(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        std::stack<std::pair<int, TreeNode*>> q;
        q.push(std::make_pair(1, root));
        int max = 0;
        while (!q.empty()) {
            // Grab the top of the stack and pop it off
            auto currentNode = q.top();
            q.pop();
            
            // Check if this a higher max and then enqueue the child nodes
            auto nodeDepth = currentNode.first;
            auto node = currentNode.second;
            max = std::max(max, nodeDepth);
            
            if (node->right != nullptr) {
                q.push(std::make_pair(nodeDepth + 1, node->right));
            }
            
            if (node->left != nullptr) {
                q.push(std::make_pair(nodeDepth + 1, node->left));
            }       
        }
        
        return max;
    }
};
