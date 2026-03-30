class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i;
    int span;
    StockSpanner() {
        i=-1;
        
    }
    
    int next(int price) {
        i++;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(st.empty()) span = i+1;
        else span = i - st.top().second;
        st.push({price,i});
    
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */