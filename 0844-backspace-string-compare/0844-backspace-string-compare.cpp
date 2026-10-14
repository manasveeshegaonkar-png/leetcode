class Solution {
public:
    bool backspaceCompare(string s, string t) {
           int i = s.size() - 1;
        int j = t.size() - 1;

        while (i >= 0 || j >= 0) {
            i = getNextValidIndex(s, i);
            j = getNextValidIndex(t, j);

            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else {
                // One string has characters left,
                // but the other does not.
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }

            i--;
            j--;
        }

        return true;
    }

private:
    int getNextValidIndex(string& s, int index) {
        int backspaces = 0;

        while (index >= 0) {
            if (s[index] == '#') {
                backspaces++;
            } else if (backspaces > 0) {
                backspaces--;
            } else {
                break;
            }

            index--;
        }

        return index;
    }
};