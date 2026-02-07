class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k= s1.size();
        if(k>s2.size()) return false;
        int H[26]={0};
        for(int i=0; i<k; i++){
            H[s1[i]-97] += 1;
            H[s2[i]-97] -= 1;

        }
        bool ok=true;
        for(int j=0; j<26; j++){
            if(H[j] != 0){
                ok = false;
                break;
            }
        }
        if(ok) return true;

        for(int i=k; i<s2.size();i++){
            H[s2[i]-'a']--;
            H[s2[i - k] - 'a']++;
            ok = true;
            for (int j = 0; j < 26; j++) {
                if (H[j] != 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;

        }
        return false;






    }
};