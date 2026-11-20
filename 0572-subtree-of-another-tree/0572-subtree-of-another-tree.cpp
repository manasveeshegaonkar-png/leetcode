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

    // Checks whether two trees are exactly identical
    bool isSame(TreeNode* a, TreeNode* b) {

        // Both trees are empty
        if (a == NULL && b == NULL)
            return true;

        // Only one tree is empty
        if (a == NULL || b == NULL)
            return false;

        // Values must match, and both children must match
        return (a->val == b->val) &&
               isSame(a->left, b->left) &&
               isSame(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // An empty subtree is present in every tree
        if (subRoot == NULL)
            return true;

        // Main tree is empty, but subtree is not
        if (root == NULL)
            return false;

        // Check if trees match from the current node
        if (isSame(root, subRoot))
            return true;

        // Search in left or right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
