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
    // Strategy
    //  - Recursively iterate through the list keeping track of the level of each node. If we do a pre-order
    //    traversal than
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        levelOrderRec(root, levels, 0);
        return levels;
    }
    
private:
    
    void levelOrderRec(TreeNode* root, vector<vector<int>>& levels, int currentLevel) {
        // Base case at a leaf
        if (root == nullptr) {
            return;
        }
        
        // Make sure we initialize all of our vector levels
        if (currentLevel >= levels.size()) {
            levels.push_back(std::vector<int>{});
        }
        
        levelOrderRec(root->left, levels, currentLevel + 1);
        levels[currentLevel].push_back(root->val);
        levelOrderRec(root->right, levels, currentLevel + 1);
        
    }
    
};
