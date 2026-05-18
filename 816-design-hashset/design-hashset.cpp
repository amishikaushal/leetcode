class MyHashSet {
public:
    unordered_set<int> seen;
    MyHashSet() {
        
    }
    
    void add(int key) {
        seen.insert(key);
    }
    
    void remove(int key) {
        if(seen.count(key)){
            seen.erase(key);
        }
    }
    
    bool contains(int key) {
        return seen.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */