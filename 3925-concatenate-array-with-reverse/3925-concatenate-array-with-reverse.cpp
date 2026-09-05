class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        //store the original array
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        //reverse nums using two pointers
        int i=0,j=n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++,j--;
        }
        //add the reverse array
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        return ans;
     }
};