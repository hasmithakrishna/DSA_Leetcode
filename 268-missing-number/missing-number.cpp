class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        vector<int> array(n+1,0);
        for(int i=0; i<n; i++){
            array[nums[i]]++;
        }
        for(int i=0; i<=n; i++){
            if(array[i]==0)
            return i;
        }
        return -1;
        
        
    }
};