
class KthLargest {
private:
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq;

    int k;

public:
    KthLargest(int k, vector<int>& nums) {

        this->k = k;

        // Insert all initial numbers
        for (int num : nums) {
            pq.push(num);

            // Maintain only k largest elements
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {

        // Insert the new number
        pq.push(val);

        // Remove smallest if size exceeds k
        if (pq.size() > k) {
            pq.pop();
        }

        // Top is the kth largest element
        return pq.top();
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */