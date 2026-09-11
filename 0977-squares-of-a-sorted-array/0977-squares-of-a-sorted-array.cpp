class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        vector<int>ans(nums.size());
        int i=nums.size()-1;
        while(left<=right){
            int leftSquare=nums[left]*nums[left];
            int rightSquare=nums[right]*nums[right];
            if(leftSquare>rightSquare){
                ans[i]=leftSquare;
                left++;
            }
            else{
                ans[i]=rightSquare;
                right--;
            }
            i--;
        }
        return ans;
    }
};