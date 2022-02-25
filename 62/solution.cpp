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
    // For each node you just swap left/right pointers I think
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        
        auto tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        
        invertTree(root->right);
        invertTree(root->left);
        
        return root;
    }
};
