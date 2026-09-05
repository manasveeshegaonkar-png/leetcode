class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        //if target should come before 1st element
        if(nums[0]>=target){
            return 0;
        }
        //find position between two elements
        for(int i=0;i<n-1;i++){
            if(nums[i]<target  && nums[i+1]>=target){
                return i+1;
            }
        }
        //target is greater than all elements
        return n;
     }
    
};