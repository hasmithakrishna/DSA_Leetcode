class Solution {

public:
    bool allzero(int freq[26]){
        for (int j = 0; j < 26; j++) {
            if (freq[j] != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length();
        int k = p.length();
        if (n < k) return ans;

        int freq[26] ={0};
        for(int i=0; i<k; i++){
            freq[p[i]-97]++;
        }
        for(int i=0; i<k; i++){
            freq[s[i]-97]--;
            }
        if(allzero(freq)) ans.push_back(0);
        for(int i=k; i<n; i++){
            freq[s[i]-97]--;
            freq[s[i-k]-97]++;
            if(allzero(freq)) ans.push_back(i-k+1);
        }
        return ans;
        

        
    }
};