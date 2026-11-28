
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        // Step 1: Store projects as {capital, profit}
        vector<pair<int, int>> projects;

        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Step 2: Sort projects by required capital
        sort(projects.begin(), projects.end());

        // Step 3: Create Max Heap for profits
        priority_queue<int> pq;

        int i = 0;

        // Step 4: Perform at most k projects
        while (k--) {

            // Add all affordable projects
            while (i < projects.size() && projects[i].first <= w) {

                pq.push(projects[i].second);
                i++;
            }

            // No project is affordable
            if (pq.empty()) {
                break;
            }

            // Choose the project with highest profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
