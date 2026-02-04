class LRUCache {
public:
    class node {
    public:
        int key, val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
            next = prev = nullptr;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newn) {
        node* temp = head->next;
        newn->next = temp;
        newn->prev = head;
        head->next = newn;
        temp->prev = newn;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            node* resnode = mpp[key];
            int res = resnode->val;
            mpp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            node* existing = mpp[key];
            mpp.erase(key);
            deletenode(existing);
        }
        if ((int)mpp.size() == cap) {
            
            node* lru = tail->prev;
            mpp.erase(lru->key);
            deletenode(lru);
        }
        
        node* newn = new node(key, value);
        addnode(newn);
        mpp[key] = head->next;
    }
};
