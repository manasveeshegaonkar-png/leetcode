class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum=0;
        for(int x:candies){
            maximum=max(maximum,x);
        }
        vector<bool>ans;
        for(int x:candies){
            if(x+extraCandies >=maximum){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};