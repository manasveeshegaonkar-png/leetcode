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

    bool check(TreeNode* root, long long minVal,
               long long maxVal) {

        // Empty tree is a valid BST
        if (root == NULL)
            return true;

        // Check whether current value is in valid range
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Check left subtree
        bool left = check(root->left, minVal, root->val);

        // Check right subtree
        bool right = check(root->right, root->val, maxVal);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
