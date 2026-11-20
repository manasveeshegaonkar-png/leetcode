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

    // Helper function to check mirror trees
    bool isMirror(TreeNode* p, TreeNode* q) {

        // Both nodes are NULL
        if(p == NULL && q == NULL)
            return true;

        // Only one node is NULL
        if(p == NULL || q == NULL)
            return false;

        // Values must be equal
        // Compare opposite children
        return (p->val == q->val) &&
               isMirror(p->left, q->right) &&
               isMirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {

        // Empty tree is symmetric
        if(root == NULL)
            return true;

        // Compare left and right subtrees
        return isMirror(root->left, root->right);
    }
};
