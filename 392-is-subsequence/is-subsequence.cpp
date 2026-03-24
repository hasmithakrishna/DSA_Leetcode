class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        if(s.empty()) return true;
        for(int i=0; i<t.size();i++){
            if(j<s.size() && t[i] == s[j]){
                j++;
                if(j==s.size()) return true;
            }
        }

        return false;
    }
};