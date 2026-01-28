class Solution {
public:
    vector<int> Arr;
    int fib(int n) {
        if(Arr.empty()){
            Arr.assign(n+1,-1);
        }
        if(n <= 1){
            Arr[n] = n;
            return n;
        }
        if(Arr[n-2] == -1){
            Arr[n-2] = fib(n-2);
        }
        if(Arr[n-1] == -1){
            Arr[n-1] = fib(n-1);
        }
        return Arr[n-2] + Arr[n-1];

        
    }
};