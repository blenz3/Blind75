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
    
#if 0
    // Do an inorder traversal and see if it is sorted
    //  - Runtime linear
    //  - Space linear
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        vector<int> values;
        inOrderTraversal(root, values);
        
        bool isValid(true);
        for (int i = 1; i < values.size(); ++i) {
            isValid &= (values[i - 1] < values[i]);
        }
        
        return isValid;
    }
    
    void inOrderTraversal(TreeNode* root, vector<int>& values) {
        if (root == nullptr) {
            return;
        }
        
        inOrderTraversal(root->left, values);
        values.push_back(root->val);
        inOrderTraversal(root->right, values);
    }
#endif
    
    // For each subtree ensure that the current node and it's immediate children conform to 
    // the invariant that the root val is between the left and right children values. 
    // Also pass in a subtree min and max value to ensure that they don't violate and subsequent 
    // values in the tree (e.g. a subtree could be valid but it's right child could be massive and
    // not belong in the overall subtree)
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        // Check for root node being valid
        if ((root->left != nullptr && root->left->val >= root->val) ||
            (root->right != nullptr && root->right->val <= root->val))
            return false;
            
        return isValidBSTRec(root->left, std::numeric_limits<int64_t>::min(), root->val) && 
                isValidBSTRec(root->right, root->val, std::numeric_limits<int64_t>::max());
        
    }
    
    bool isValidBSTRec(TreeNode* root, int64_t subtreeMin, int64_t subtreeMax) {
        if (root == nullptr) return true;
        
        
        bool currentValid = (root->left == nullptr || (int64_t)root->val > root->left->val) &&
                            (root->right == nullptr || (int64_t)root->val < root->right->val) &&
                            (root->left == nullptr || (int64_t)root->left->val > subtreeMin) &&
                            (root->right == nullptr || (int64_t)root->right->val < subtreeMax);
        
        if (!currentValid) {
            return false;
        }
        
        return isValidBSTRec(root->left, subtreeMin, root->val) && 
               isValidBSTRec(root->right, root->val, subtreeMax);
    }

};
