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
    // Just try to traverse each of the nodes if anything doesn't match they aren't equal
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return equalityTraverse(p, q);
    }
    
private:
    bool equalityTraverse(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if ((p != nullptr) != (q != nullptr)) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        if (!equalityTraverse(p->left, q->left) || !equalityTraverse(p->right, q->right)) {
            return false;
        }
            
        return true;
    }
};
