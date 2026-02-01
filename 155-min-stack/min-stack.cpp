class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }

        else if(val >= mini){
            st.push(val);
        }
        else{
            
            st.push(2LL * val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long topi = st.top();
        st.pop();

        if (topi < mini) {
            mini = 2LL * mini - topi;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long topi = st.top();

        if (topi < mini) {
            return (int)mini;
        }
        return (int)topi;
    }
    
    int getMin() {
        return (int) mini;
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