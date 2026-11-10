class Solution {
public:
    int calPoints(vector<string>& operations) {
       stack<int>st;
       for(int i=0;i<operations.size();i++){
        //if operation is c
        if(operations[i]=="C"){
            st.pop();
        }
        //if operation is d
        else if(operations[i]=="D"){
            int x=st.top();
            st.push(x*2);
        }
        //if operation is +
        else if(operations[i]=="+"){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.push(x);
            st.push(x+y);
        }
        //if operation is an integer
        else{
            st.push(stoi(operations[i]));//stoi->string to integer as given is string and we want integers for these operations
        }
       } 
       //calculate total score
       int sum=0;
       while(!st.empty()){
        sum+=st.top();
        st.pop();
       }
       return sum;
    }
};