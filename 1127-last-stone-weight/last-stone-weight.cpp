class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int &it : stones){
            pq.push(it);
        }

        while(pq.size() > 1){
            int top1 = pq.top();
            pq.pop();

            int top2 = pq.top();
            pq.pop();


            if(top1 != top2){
                pq.push(abs(top1 - top2));
            }

        }

        if(pq.empty()){
            return 0;
        }
        else{
            return pq.top();
        }
        

    }
};