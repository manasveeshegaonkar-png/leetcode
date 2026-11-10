class Solution {
public:
    string process(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '#') {

                if(!st.empty()) {
                    st.pop();
                }

            }
            else {
                st.push(s[i]);
            }
        }

        // Convert stack into string
        string result = "";

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }

    bool backspaceCompare(string s, string t) {

        string a = process(s);
        string b = process(t);

        return a == b;
    }
};