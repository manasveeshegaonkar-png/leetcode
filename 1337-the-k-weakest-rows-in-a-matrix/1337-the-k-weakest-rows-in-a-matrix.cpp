
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        // Step 1: Create Min Heap
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Step 2: Count soldiers in each row
        for (int i = 0; i < mat.size(); i++) {

            int soldiers = 0;

            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    soldiers++;
                }
            }

            // Store {soldiers, row index}
            pq.push({soldiers, i});
        }

        // Step 3: Get k weakest rows
        vector<int> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
