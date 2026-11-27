
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of tasks
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Step 2: Create Max Heap
        priority_queue<int> pq;

        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        // Step 3: Create Queue
        queue<pair<int, int>> q;

        int time = 0;

        // Step 4: Process tasks
        while (!pq.empty() || !q.empty()) {

            time++;

            // Execute task with highest frequency
            if (!pq.empty()) {

                int remaining = pq.top();
                pq.pop();

                remaining--;

                // If task still remains, put it in queue
                if (remaining > 0) {
                    q.push({remaining, time + n});
                }
            }

            // Check if a task's cooldown is finished
            if (!q.empty() && q.front().second == time) {

                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
