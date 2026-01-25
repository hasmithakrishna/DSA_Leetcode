class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum =0, maximsum = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            currentsum += nums[i];
            maximsum = max(maximsum, currentsum);
            if(currentsum<0){
                currentsum = 0;
            }
        }
        return maximsum;
        
    }
};