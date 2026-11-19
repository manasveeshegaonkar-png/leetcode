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
    vector<vector<int>> levelOrder(TreeNode* root) {

        // Store the final answer
        vector<vector<int>> ans;

        // Handle an empty tree
        if(root == NULL)
            return ans;

        // Queue for BFS traversal
        queue<TreeNode*> q;

        // Insert root into queue
        q.push(root);

        // Process until queue becomes empty
        while(!q.empty()) {

            // Number of nodes at current level
            int size = q.size();

            // Store values of current level
            vector<int> level;

            // Process all nodes of this level
            for(int i = 0; i < size; i++) {

                // Get the front node
                TreeNode* node = q.front();
                q.pop();

                // Store its value
                level.push_back(node->val);

                // Add left child if it exists
                if(node->left != NULL)
                    q.push(node->left);

                // Add right child if it exists
                if(node->right != NULL)
                    q.push(node->right);
            }

            // Add completed level to answer
            ans.push_back(level);
        }

        return ans;
    }
};
