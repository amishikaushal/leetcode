class RangeModule {
public:
    map<int , int> mpp;

    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = mpp.lower_bound(left);

        if(it != mpp.begin()){
            auto prev = it;
            prev--;

            if(prev -> second >= left){
                it = prev;
            }
        }

        while( it != mpp.end() && it -> first <= right){
            left = min(left , it -> first);
            right = max(right , it -> second);

            it = mpp.erase(it);
        }

        mpp[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = mpp.upper_bound(left);

        if(it == mpp.begin()){
            return false;
        }

        it--;

        return it -> second >= right;
    }
    
    void removeRange(int left, int right) {
        auto it = mpp.lower_bound(left);

        if(it != mpp.begin()){
            auto prev = it;

            prev--;

            if(prev -> second > left ){
                it = prev;
            }
        }

        while(it != mpp.end() && it -> first < right){
            int L = it -> first;

            int R = it -> second;

            it = mpp.erase(it);

            if(L < left){
                mpp[L] = left;
            }


            if(R > right){
                mpp[right] = R;
            }

        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */