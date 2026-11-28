
class Solution {
public:
    string reorganizeString(string s) {

        // Step 1: Count frequency
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Create Max Heap
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], 'a' + i});
            }
        }

        // Step 3: Build answer
        string ans = "";

        while (!pq.empty()) {

            auto first = pq.top();
            pq.pop();

            // Check if same character would become adjacent
            if (!ans.empty() && ans.back() == first.second) {

                // No other character is available
                if (pq.empty()) {
                    return "";
                }

                // Take the second most frequent character
                auto second = pq.top();
                pq.pop();

                ans += second.second;
                second.first--;

                if (second.first > 0) {
                    pq.push(second);
                }

                // Put first character back
                pq.push(first);
            }
            else {

                // Add first character
                ans += first.second;
                first.first--;

                if (first.first > 0) {
                    pq.push(first);
                }
            }
        }

        return ans;
    }
};
