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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int& preIndex, int inStart, int inEnd) {

        // No elements left to construct
        if (inStart > inEnd)
            return NULL;

        // First preorder element is the root
        int rootValue = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int inIndex = inStart;

        while (inorder[inIndex] != rootValue) {
            inIndex++;
        }

        // Build left and right subtrees
        root->left = build(preorder, inorder, preIndex,
                           inStart, inIndex - 1);

        root->right = build(preorder, inorder, preIndex,
                            inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preIndex = 0;

        return build(preorder, inorder, preIndex,
                     0, inorder.size() - 1);
    }
};