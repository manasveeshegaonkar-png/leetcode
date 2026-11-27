
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {

        // Step 1: Create Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Step 2: Insert all elements
        for (int num : nums) {
            pq.push(num);
        }

        // Step 3: Perform k operations
        while (k--) {

            // Get the smallest element
            int smallest = pq.top();
            pq.pop();

            // Increase it by 1
            smallest++;

            // Insert it back
            pq.push(smallest);
        }

        // Step 4: Calculate product
        long long product = 1;
        int mod = 1e9 + 7;

        while (!pq.empty()) {
            product = (product * pq.top()) % mod;
            pq.pop();
        }

        return product;
    }
};
