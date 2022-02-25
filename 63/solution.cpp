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
    int maxPathSum(TreeNode* root) {
        int maxSoFar = INT_MIN;
        maxSubTree(root, maxSoFar);
        return maxSoFar;
    }
    
private:
    int maxSubTree(TreeNode* root, int& maxSubtreeSum) {
        if (root == nullptr) {
            return 0;
        }
        
        int currentValue = root->val;
        int leftMax = maxSubTree(root->left, maxSubtreeSum);
        int rightMax = maxSubTree(root->right, maxSubtreeSum);
        
        if (leftMax > 0) {
            currentValue += leftMax;
        }
        
        if (rightMax > 0) {
            currentValue += rightMax;
        }
        
        maxSubtreeSum = std::max(maxSubtreeSum, currentValue);
        
        int outputMax =  std::max(leftMax, rightMax);
        if (outputMax > 0) {
            return root->val + outputMax;
        } else {
            return root->val;
        }
    }
};
