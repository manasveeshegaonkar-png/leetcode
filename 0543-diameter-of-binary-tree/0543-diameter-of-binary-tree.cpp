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

    // Stores the maximum diameter
    int diameter = 0;

    // Function to calculate height
    int height(TreeNode* root) {

        // Base case
        if(root == NULL)
            return 0;

        // Calculate left subtree height
        int leftHeight = height(root->left);

        // Calculate right subtree height
        int rightHeight = height(root->right);

        // Update maximum diameter
        // Diameter = left height + right height
        diameter = max(diameter,
                       leftHeight + rightHeight);

        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        // Calculate heights and diameter
        height(root);

        return diameter;
    }
};
