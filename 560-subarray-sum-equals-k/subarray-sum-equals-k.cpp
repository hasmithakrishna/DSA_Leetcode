class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        mp[0] = 1;
        int psum = 0;
        for(int i=0; i<nums.size(); i++){
            psum += nums[i];
            if(mp.find(psum-k) != mp.end()){
                count += mp[psum-k];
            }
            mp[psum]++;
        }
        return count;
    }
};