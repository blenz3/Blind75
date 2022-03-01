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
    // Terrible solution
    //  - Create an array from all the values and grab the kth smallest. Preorder traversal will
    //    give us a sorted list so it's easy
    //  - Time O(n)
    //  - Space O(n)
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }
        
        vector<int> values;
        getPreorderValues(root, values);
        
        return values[k - 1];
    }
    
    
    void getPreorderValues(TreeNode* root, std::vector<int>& values) {
        if (root == nullptr) {
            return;
        }
        
        getPreorderValues(root->left, values);
        values.push_back(root->val);
        getPreorderValues(root->right, values);        
    }
#endif
    
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }
        
        int result(0);
        kthSmallestRec(root, k, result);    
        return result;
    }
    
    void kthSmallestRec(TreeNode* root, int& k, int& result) {
        // We made it to the smallest node this is our base case
        if (root == nullptr) {
            return;
        }
        
        // Recurse left to continue finding the smallest element
        kthSmallestRec(root->left, k, result);
        
        
        // We've found our value
        if (k == 1) {
            result = root->val;
        }
        
        k--;
        kthSmallestRec(root->right, k, result);
    }
};
