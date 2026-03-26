class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    int minim= INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        minim = min(minim, val);
        minst.push(minim);
    }
    
    void pop() {
        st.pop();
        minst.pop();
        if(!st.empty()) minim = minst.top();
        else
        minim = INT_MAX;
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */