
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // Create a Max Heap
        priority_queue<int> pq;

        // Insert all stones into heap
        for (int stone : stones) {
            pq.push(stone);
        }

        // Continue until at most one stone remains
        while (pq.size() > 1) {

            // Get the two heaviest stones
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            // If weights are different
            if (first != second) {

                // Insert the remaining weight
                pq.push(first - second);
            }
        }

        // If heap is empty, return 0
        if (pq.empty()) {
            return 0;
        }

        // Return the last remaining stone
        return pq.top();
    }
};
