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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // Handle empty tree
        if(root == NULL)
            return ans;

        // Queue for BFS
        queue<TreeNode*> q;

        q.push(root);

        // Controls traversal direction
        bool leftToRight = true;

        while(!q.empty()) {

            int size = q.size();

            vector<int> level;

            // Process all nodes of current level
            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                // Add left child
                if(node->left != NULL)
                    q.push(node->left);

                // Add right child
                if(node->right != NULL)
                    q.push(node->right);
            }

            // Reverse alternate levels
            if(!leftToRight) {
                reverse(level.begin(), level.end());
            }

            // Store current level
            ans.push_back(level);

            // Change direction for next level
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
