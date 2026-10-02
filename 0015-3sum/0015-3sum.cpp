class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;//store all valid triplets
        //step1-sort the array
        sort(nums.begin(),nums.end());
        //step2-fix one element
        for(int i=0;i<nums.size()-2;i++){
            //skip duplicate values of nums[i]
            if(i>0 && nums[i]==nums[i-1])
            continue;
            //two pointers for the remaining elements
            int left=i+1;
            int right=nums.size()-1;
            //search for two elements whose sum is -nums[i]
            while(left<right){
                int sum= nums[i]+nums[left]+nums[right];
                //found a triplet
                if(sum==0){
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });
                    //skip duplicate left values
                    while(left<right && nums[left]==nums[left+1])
                    left++;
                    //skip duplicate right values
                    while(left<right && nums[right]==nums[right-1])
                    right--;
                    //move both pointers
                    left++;
                    right--;
                }
                //sum is too small->increase it
                else if(sum<0){
                    left++;
                }
                //sum is too large->decrease it
                else{
                    right--;
                }
            }
        }
        return ans;
    }
};