
class Solution {
public:
    string removeDuplicates(string s) {

        // Create a stack to store characters
        stack<char> st;

        // Traverse the given string
        for(int i = 0; i < s.length(); i++) {

            // If stack is not empty and
            // current character matches stack's top
            if(!st.empty() && st.top() == s[i]) {

                // Remove the duplicate character
                st.pop();
            }

            else {

                // If characters are different,
                // push the current character
                st.push(s[i]);
            }
        }

        // Create a string to store the final answer
        string ans = "";

        // Extract all characters from the stack
        while(!st.empty()) {

            ans += st.top();

            st.pop();
        }

        // Reverse because stack follows LIFO
        reverse(ans.begin(), ans.end());

        // Return the final string
        return ans;
    }
};
