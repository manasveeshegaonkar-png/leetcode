
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Create a Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert every element into the heap
        for (int num : nums) {

            pq.push(num);

            // Keep only k largest elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Top element is the kth largest
        return pq.top();
    }
};
