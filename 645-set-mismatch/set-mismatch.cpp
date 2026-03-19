class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        int v1, v2;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=1; i<=nums.size(); i++){
            if(mp[i] == 2) v1 =i;
            else if(mp[i] == 0) v2=i;
        }
        return {v1,v2};
        
    }
};