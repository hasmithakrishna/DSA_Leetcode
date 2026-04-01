class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> result;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto i=mp.begin(); i!= mp.end();i++){
            heap.push({i->second,i->first});
            if(heap.size()>k) heap.pop();
        }
        while(!heap.empty()){
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;

    }
};