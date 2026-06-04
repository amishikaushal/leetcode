class FreqStack {
public:
    unordered_map<int , int> mpp;
    unordered_map<int , stack<int>> grp;
    int maxfreq ;
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int val) {
        int f = ++mpp[val];
        grp[f].push(val);

        maxfreq = max(maxfreq , f);
    }
    
    int pop() {
        if(grp[maxfreq].empty()){
            maxfreq--;
        }

        int val = grp[maxfreq].top();
        grp[maxfreq].pop();

        mpp[val]--;

        if(grp[maxfreq].empty()){
            maxfreq--;
        }
        return val;




    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */