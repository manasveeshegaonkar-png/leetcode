
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        // Check each row
        for (int i = 0; i < m; i++) {

            int low = 0;
            int high = n - 1;

            // Find first negative number
            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (grid[i][mid] < 0) {
                    high = mid - 1; // Search left
                }
                else {
                    low = mid + 1;  // Search right
                }
            }

            // All elements from low to end are negative
            count += n - low;
        }

        return count;
    }
};
