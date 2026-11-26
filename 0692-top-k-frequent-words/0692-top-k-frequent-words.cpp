
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequency of each word
        unordered_map<string, int> freq;

        for (string word : words) {
            freq[word]++;
        }

        // Step 2: Create a custom comparator
        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {

            // If frequencies are equal,
            // lexicographically larger word comes first (is worse)
            if (a.first == b.first) {
                return a.second < b.second;
            }

            // Lower frequency comes first (is worse)
            return a.first > b.first;
        };

        // Step 3: Create a Min Heap
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype(cmp)
        > pq(cmp);

        // Step 4: Insert words into heap
        for (auto it : freq) {

            pq.push({it.second, it.first});

            // Keep only k most frequent words
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 5: Extract words
        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Heap gives worst-to-best order, so reverse it
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
