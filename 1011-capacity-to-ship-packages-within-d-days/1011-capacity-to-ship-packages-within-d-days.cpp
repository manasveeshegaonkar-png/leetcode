
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int requiredDays = 1;
            int currentWeight = 0;

            // Check how many days are needed with capacity mid
            for (int weight : weights) {

                if (currentWeight + weight <= mid) {
                    currentWeight += weight;
                }
                else {
                    requiredDays++;
                    currentWeight = weight;
                }
            }

            // Capacity is sufficient
            if (requiredDays <= days) {
                ans = mid;
                high = mid - 1;
            }
            else {
                // Capacity is insufficient
                low = mid + 1;
            }
        }

        return ans;
    }
};
