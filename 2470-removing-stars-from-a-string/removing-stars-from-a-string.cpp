class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        string result = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] != '*') st.push(s[i]);
            else{
                st.pop();
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;

        
    }
};