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
    bool hasPathSum(TreeNode* root, int targetSum) {

        // If node is NULL, no path exists
        if (root == NULL)
            return false;

        // Subtract current node's value
        targetSum -= root->val;

        // Check if current node is a leaf
        if (root->left == NULL && root->right == NULL) {

            // Path is valid if remaining sum is 0
            return targetSum == 0;
        }

        // Check left or right subtree
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
