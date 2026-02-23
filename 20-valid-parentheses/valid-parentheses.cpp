class Solution {
public:
    bool isValid(string s) {
        int n = int(s.size());
        char *Arr = new char[n];
        int top=-1;
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                if(top==n-1) return false;
                top++;
                Arr[top] = s[i];
            }
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(top==-1) return false;
                char open = Arr[top];
                top--;
                if((open =='(' && s[i] !=')') || 
                (open =='[' && s[i] !=']') || 
                (open =='{' && s[i] !='}'))
                return false; 
                
            }
        }
        return (top==-1); 
    }
};