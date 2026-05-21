class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum = 0;
        int maxim = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            cursum += nums[i];
            maxim = max(cursum, maxim);
            if(cursum < 0) cursum = 0;
        }
        return maxim;
        
    }
};