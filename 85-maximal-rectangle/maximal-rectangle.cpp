class Solution {
public:
    int MaxHistogram(vector<int>& heights){
        vector<int> left;
        vector<int> right;
        stack<pair<int,int>> st;

        int maximum = 0;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && st.top().first >= heights[i]) st.pop();
            if(st.empty()) left.push_back(-1);
            else left.push_back(st.top().second);
            st.push({heights[i],i});
        }
        while(!st.empty()) st.pop();
        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first >= heights[i]) st.pop();
            if(st.empty()) right.push_back(heights.size());
            else right.push_back(st.top().second);
            st.push({heights[i],i});
        }
        reverse(right.begin(), right.end());
        for(int i=0; i<heights.size(); i++){
            int width = right[i] -left[i] -1;
            int area = width*heights[i];
            maximum = max(maximum, area);
        }
        return maximum;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;

        int m = matrix.size();
        int n = matrix[0].size();
        for(int j=0; j<n; j++){
            v.push_back(matrix[0][j]-'0'); 
            }
        int mx = MaxHistogram(v);
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='0') v[j] = 0;
                else v[j] = v[j] + matrix[i][j]-'0';
            }
            mx = max(mx, MaxHistogram(v));
        }
        return mx; 
    }
};