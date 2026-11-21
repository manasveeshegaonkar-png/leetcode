
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = 0;

            // Calculate total hours needed at speed mid
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            // Speed is sufficient, try a smaller speed
            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            }

            // Speed is too slow, increase it
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
