class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == k) count++;
            int prefixsum = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                prefixsum += nums[j];
                if(prefixsum==k) count++;
            }
        }
        return count;
        
    }
};