class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            //if opening bracket, push into stack
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                st.push(s[i]);
            }
            //if closing bracket
            else{
                //no opening bracket available
                if(st.empty()){
                    return false;
                }
                //check matching brackets
                if(s[i]==')' && st.top()=='('||
                   s[i]=='}' && st.top()=='{'||
                   s[i]==']' && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        //stack should be empty
        return st.empty();
    }
};