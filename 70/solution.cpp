/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min = std::min(p->val, q->val);
        int max = std::max(p->val, q->val);
        while (root != nullptr) {
            if (root->val >= min && root->val <= max) {
                return root;
            } else if (root->val < min) {
                root = root->right;
            } else { // current val is greater than the max
                root = root->left;
            }
        }
        
        return nullptr;
    }
    
#if 0
    // Recursion
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min = std::min(p->val, q->val);
        int max = std::max(p->val, q->val);
        return lcaRec(root, min, max);
    }
    
private:
    TreeNode* lcaRec(TreeNode* root, int minVal, int maxVal) {
        if (root->val >= minVal && root->val <= maxVal) {
            return root;
        } else if (root->val < minVal) {
            return lcaRec(root->right, minVal, maxVal);
        } else {
            return lcaRec(root->left, minVal, maxVal);
        }
    }
#endif
};
