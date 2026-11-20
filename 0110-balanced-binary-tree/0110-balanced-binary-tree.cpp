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

    // Function to calculate height
    // and check whether the tree is balanced
    int height(TreeNode* root) {

        // Base case: Empty tree has height 0
        if(root == NULL)
            return 0;

        // Calculate left subtree height
        int leftHeight = height(root->left);

        // If left subtree is unbalanced
        if(leftHeight == -1)
            return -1;

        // Calculate right subtree height
        int rightHeight = height(root->right);

        // If right subtree is unbalanced
        if(rightHeight == -1)
            return -1;

        // Check height difference
        if(abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return current subtree height
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        // If height returns -1,
        // tree is not balanced
        return height(root) != -1;
    }
};
