class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=0;
        int sum=0;
        int minLength=INT_MAX;
        while(high<nums.size()){
            //expand the window
            sum=sum+nums[high];
            //shrink the window
            while(sum>=target){
                int length=high-low+1;
                minLength=min(minLength,length);
                sum=sum-nums[low];
                low++;
            }
            high++;
        }
        if(minLength==INT_MAX)
           return 0;
        return minLength;
    }
};