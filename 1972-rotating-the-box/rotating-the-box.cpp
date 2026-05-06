class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // Step 1: Apply gravity (right direction)
        for(int i = 0; i < m; i++){
            int empty = n - 1;  // position where next stone can fall

            for(int j = n - 1; j >= 0; j--){
                if(box[i][j] == '*'){
                    empty = j - 1; // reset after obstacle
                }
                else if(box[i][j] == '#'){
                    swap(box[i][j], box[i][empty]);
                    empty--;
                }
            }
        }

        // Step 2: Rotate matrix (clockwise)
        vector<vector<char>> res(n, vector<char>(m));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res[j][m - 1 - i] = box[i][j];
            }
        }

        return res;
    }
};