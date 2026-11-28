
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        // Step 1: Create max heap
        priority_queue<pair<int,int>> pq;

        // Step 2: Insert elements
        for(int num : arr) {
            int dist = abs(num - x);
            pq.push({dist, num});

            // Keep only k closest elements
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // Step 3: Store the answer
        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Step 4: Sort the answer
        sort(ans.begin(), ans.end());

        return ans;
    }
};
