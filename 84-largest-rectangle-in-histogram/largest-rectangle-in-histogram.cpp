class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> Left;
        vector<int> Right;
        stack<pair<int,int>> st1;
        int maximum = 0;
        for(int i=0; i<heights.size();i++){
            while(!st1.empty() && st1.top().first >= heights[i]) st1.pop();
                if(st1.empty()) Left.push_back(-1);
                else Left.push_back(st1.top().second);
            st1.push({heights[i],i});
        }
        while(!st1.empty()){
            st1.pop();
        }
        for(int i= heights.size()-1; i>=0; i--){
            while(!st1.empty() && st1.top().first >= heights[i]) st1.pop();
            if(st1.empty()) Right.push_back(heights.size());
            else Right.push_back(st1.top().second);

            st1.push({heights[i],i});
        }
        reverse(Right.begin(), Right.end());
        for(int i=0; i<heights.size(); i++){
            int width = Right[i] - Left[i] - 1;
            int area = width*heights[i];
            maximum = max(area, maximum);
        
        }
        return maximum;



        
    }
};