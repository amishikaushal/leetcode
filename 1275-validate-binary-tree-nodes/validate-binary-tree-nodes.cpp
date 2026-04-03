class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //iiiiiiiiillllllooooooovvvvveeeeeeeaaammmmiiiissshhhhiiii.


        int m = leftChild.size();

        vector<int> parent(n , -1);

        for(int i = 0; i < n ; i++){
            if(leftChild[i] != -1){
                if(parent[leftChild[i]] == -1){
                    parent[leftChild[i]] = i;
                }
                else{
                    return false;
                }
            }


            if(rightChild[i] != -1){
                if(parent[rightChild[i]] == -1){
                    parent[rightChild[i]] = i;
                }
                else{
                    return false;
                }
            }
        }
        int root = -1;

        for(int i = 0; i < n ; i++){
            if(parent[i] == -1){
                if(root != -1) return false;
                root = i;
            }
        }


        if(root == -1) return false;

        queue<int> q;
        vector<int> vis(n , 0);

        q.push(root);
        vis[root] = 1;

        int cnt = 0;

        while(!q.empty()){
            int i = q.front();
            q.pop();
            cnt++;

            if(leftChild[i] != -1 && !vis[leftChild[i]]){
                vis[leftChild[i]] = 1;
                q.push(leftChild[i]);
            }


             if(rightChild[i] != -1 && !vis[rightChild[i]]){
                vis[rightChild[i]] = 1;
                q.push(rightChild[i]);
            }
        }
        return cnt == n ;



    }
};