class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //sort the array
        sort(nums.begin(),nums.end());
        //store the closest sum found so far
        int closest =nums[0]+nums[1]+nums[2];
        //fix one element
        for(int i=0;i<nums.size()-2;i++){
            //two pointers
            int left=i+1;
            int right=nums.size()-1;
            //use two pointers
            while(left<right){
                int sum= nums[i]+nums[left]+nums[right];
                //if current sum is closer to target, update closest
                if(abs(sum-target)<abs(closest-target)){
                    closest=sum;
                }
                //if sum is smaller than target,increase sum
                if(sum<target){
                    left++;
                }
                //if sum is greater than target, decrease it
                else if(sum>target){
                    right--;
                }
                //exact target found
                else{
                    return sum;
                }
            }
        }
        return closest;
    }
};