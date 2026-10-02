class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0;
        int count1=0;
        int count2=0;
        //count 0,1,2
        for(int num:nums){
            if(num==0)
            count0++;
            else if(num==1)
            count1++;
            else
            count2++;
        }
        //put0s
        int i=0;

        while(count0>0){
            nums[i]=0;
            i++;
            count0--;
        }
        //put1s
        while(count1>0){
            nums[i]=1;
            i++;
            count1--;
        }
        //put2s
        while(count2>0){
            nums[i]=2;
            i++;
            count2--;
        }
    }
};