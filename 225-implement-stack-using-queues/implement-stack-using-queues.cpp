class MyStack {
private: 
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1 , q2);
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }

        int topi = q1.front();
        q1.pop();

        return topi;
    }
    
    int top(){
        if(q1.empty()){
            return -1;
        }

        int topi = q1.front();
        return topi;
    }
    
    bool empty() {
        return q1.empty();
    }
};

