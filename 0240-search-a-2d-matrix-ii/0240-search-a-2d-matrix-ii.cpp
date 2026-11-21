
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        // Start from top-right corner
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {

            if (matrix[row][col] == target) {
                return true;
            }

            // Current element is greater than target
            else if (matrix[row][col] > target) {
                col--;  // Move left
            }

            // Current element is smaller than target
            else {
                row++;  // Move down
            }
        }

        return false;
    }
};
