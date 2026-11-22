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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int& postIndex, int inStart, int inEnd) {

        // No elements left
        if (inStart > inEnd)
            return NULL;

        // Last postorder element is the root
        int rootValue = postorder[postIndex];
        postIndex--;

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int inIndex = inStart;

        while (inorder[inIndex] != rootValue) {
            inIndex++;
        }

        // Build right subtree first
        root->right = build(inorder, postorder, postIndex,
                            inIndex + 1, inEnd);

        // Then build left subtree
        root->left = build(inorder, postorder, postIndex,
                           inStart, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postIndex = postorder.size() - 1;

        return build(inorder, postorder, postIndex,
                     0, inorder.size() - 1);
    }
};