class Solution {
public:
    vector<int> Arr;
    //Can be done easily with recursion fib(n-2) + fib(n-1) but it makes repeated function calls with same values which leads to excessive recursion. So we use a concept called memorization. First we initialize an array with -1. Update that array.
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