class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        priority_queue<pair<int,int>> heap;
        for(int i=0; i<arr.size(); i++){
            heap.push({abs(arr[i]-x), arr[i]});
            if(heap.size()>k) heap.pop();
        }
        while(!heap.empty()){
            result.push_back(heap.top().second);
            heap.pop();
        }
        sort(result.begin(),result.end());
        return result;

    }
};