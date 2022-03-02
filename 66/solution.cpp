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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        
        return traverse(root, subRoot);
    }
    
    bool traverse(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        
        bool result(false);
        result |= traverse(root->left, subRoot);
        if (root->val == subRoot->val) {
            result |= checkEquality(root, subRoot);
        }
        result |= traverse(root->right, subRoot);
        
        return result;
    }
    
    bool checkEquality(TreeNode* a, TreeNode* b) {
        if ((a == nullptr) != (b == nullptr)) {
            return false;
        } else if (a == nullptr && b == nullptr) {
            return true;
        }
        
        bool result = checkEquality(a->left, b->left);
        result &= (a->val == b->val);
        result &= checkEquality(a->right, b->right);
        
        return result;
    }
};
