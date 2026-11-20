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
    TreeNode* searchBST(TreeNode* root, int val) {

        // If tree is empty or value is not found
        if (root == NULL)
            return NULL;

        // If current node contains the target
        if (root->val == val)
            return root;

        // If target is smaller, search left
        if (val < root->val)
            return searchBST(root->left, val);

        // If target is greater, search right
        return searchBST(root->right, val);
    }
};
