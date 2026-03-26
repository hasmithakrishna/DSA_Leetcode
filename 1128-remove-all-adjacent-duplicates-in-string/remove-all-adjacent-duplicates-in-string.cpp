class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        vector<char> s2;
        for(int i=0; i< s.size(); i++){
            if(st.empty() || st.top() != s[i]) st.push(s[i]);
            else
            st.pop();
        }
        while(!st.empty()){
            s2.push_back(st.top());
            st.pop();
        }
        reverse(s2.begin(), s2.end());
        string result(s2.begin(), s2.end());
        return result;
        
    }
};