class Solution {
public:
     bool isSafe(int row , int col , vector<string> &board , int n){
        int i = row;
        int j = col;

        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        row = i;
        col = j;

        while(row < n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }

        row = i ; 
        col = j;
        while (col >= 0) {
            if (board[row][col] == 'Q') {  
                return false;
            }
            col--; 
        }

        return true;
     }
    void solve(int col , vector<string> &board , vector<vector<string>> &ans , int n){
        if(col == n){
            ans.push_back(board);
            return;
        }


        for(int r = 0 ; r < n ; r++ ){
            if(isSafe(r , col , board , n)){
                board[r][col] = 'Q';


                solve( col + 1 , board , ans , n);

                board[r][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board( n , string(n , '.'));
        solve(0 , board, ans , n);

        return ans;
    }
};