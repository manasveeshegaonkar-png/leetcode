class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];
        if (mp.find(needed) != mp.end()) { // if exists
            return {mp[needed], i};
        }
        mp[nums[i]] = i; // store the current no. as a key in the map & store
                         // its index as value
    }
    return{};
    }
};