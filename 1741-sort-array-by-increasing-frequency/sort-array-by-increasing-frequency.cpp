class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        auto compare = [](const pair<int,int>&a, const pair<int,int>&b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> heap(compare);
        for(auto i = mp.begin(); i!=mp.end(); i++){
            heap.push({i->second, i->first});
        }
        while(!heap.empty()){
            for(int i=0; i<heap.top().first; i++){
                result.push_back(heap.top().second);
            }
            heap.pop();
        }
        return result;
        
        
    }
};