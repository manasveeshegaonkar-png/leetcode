
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // We are moving uphill
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }

            // We are moving downhill
            else {
                high = mid;
            }
        }

        return low;
    }
};
