class MyQueue {
private:
    stack<int> st;

public:
    void insertAtBottom( int temp){
        if(st.empty()){
            st.push(temp);
            return;
        }

        int topi = st.top();
        st.pop();


        insertAtBottom( temp);
        st.push(topi);
    }
    MyQueue() {
        
    }
    
    void push(int x) {
        insertAtBottom(x);
    }
    
    int pop() {
        int font = st.top();
        st.pop();
        return font;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */