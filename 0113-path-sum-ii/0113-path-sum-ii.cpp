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

    vector<vector<int>> ans;
    vector<int> path;

    void solve(TreeNode* root, int targetSum) {

        // Base case: empty node
        if (root == NULL)
            return;

        // Add current node to path
        path.push_back(root->val);

        // Subtract current value
        targetSum -= root->val;

        // Check if current node is a leaf
        if (root->left == NULL && root->right == NULL) {

            // If remaining sum is 0, store path
            if (targetSum == 0) {
                ans.push_back(path);
            }
        }

        // Explore left subtree
        solve(root->left, targetSum);

        // Explore right subtree
        solve(root->right, targetSum);

        // Backtrack: remove current node
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        solve(root, targetSum);

        return ans;
    }
};
