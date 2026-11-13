
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int low = 0;
        int high = letters.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (letters[mid] > target) {
                high = mid - 1;  // Search left for a smaller answer
            }

            else {
                low = mid + 1;   // Search right
            }
        }

        // Circular condition: return first character
        return letters[low % letters.size()];
    }
};
