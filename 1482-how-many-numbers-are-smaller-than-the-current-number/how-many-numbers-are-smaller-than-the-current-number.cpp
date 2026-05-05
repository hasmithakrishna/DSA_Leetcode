class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int> mp;
        mp[sorted[0]] = 0;
        vector<int> res;
        for(int i=1; i<nums.size(); i++){
            if(sorted[i] == sorted[i-1]) continue;
            else{
                mp[sorted[i]] = i;
            }
        }
        for(int i=0; i<nums.size(); i++){
            res.push_back(mp[nums[i]]);
        }
        return res;
        
    }
};