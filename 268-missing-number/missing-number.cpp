class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //We create a new array to note frequencies from 0 to n, then return the index whose frequency is zero.
        
        int n= nums.size();
        vector<int> arrayfreq(n+1,0);
        for(int i=0; i<n; i++){
            arrayfreq[nums[i]]++;
        }
        for(int i=0; i<=n; i++){
            if(arrayfreq[i]==0)
            return i;
        }
        return -1;
        
        
    }
};