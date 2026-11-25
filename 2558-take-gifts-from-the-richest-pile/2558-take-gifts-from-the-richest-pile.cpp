
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        // Create a Max Heap
        priority_queue<long long> pq;

        // Insert all piles into the heap
        for (int x : gifts) {
            pq.push(x);
        }

        // Perform exactly k operations
        while (k--) {

            // Get the largest pile
            long long largest = pq.top();
            pq.pop();

            // Take the square root (floor value)
            long long remaining = sqrt(largest);

            // Insert the modified pile back
            pq.push(remaining);
        }

        // Calculate the sum of all remaining piles
        long long sum = 0;

        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
