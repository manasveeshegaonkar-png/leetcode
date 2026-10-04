class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0;
        int high=0;
        int maxlength=0;
        unordered_map<int,int>mp;
        for(high=0;high<fruits.size();high++){
            mp[fruits[high]]++;
            while(mp.size()>2){
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0){
                    mp.erase(fruits[low]);
                }
                low++;
            }
            int length=high-low+1;
            maxlength=max(maxlength,length);
           
        }
        return maxlength;
    }
};