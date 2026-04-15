class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ld = INT_MAX, rd = INT_MAX;
        int n = words.size();
        for(int i=0; i<n; i++){
            int idx = (startIndex+i)%n;
            if(words[idx] == target){
                rd = i;
                break;
            }
        }
        for(int i=0; i<n; i++){
            int idx = (startIndex- i + n)%n;
            if(words[idx] == target){
                ld = i;
                break;
            }
        }
        int ans = min(ld,rd);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};