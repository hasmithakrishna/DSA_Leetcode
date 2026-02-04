class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if((s[i]>='A'&& s[i]<='Z') ||(s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                if (s[i] >= 'A' && s[i] <= 'Z') 
                temp += (s[i] - 'A' + 'a');
                else
                temp+=s[i];

            }
        }
        s = temp;
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
        
    }
};