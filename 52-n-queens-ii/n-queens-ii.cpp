class Solution {
public:
    int ans = 0;
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
    void solve(int col , vector<string> &board , int n){
        if(col == n){
            ans++;
            return;
        }


        for(int r = 0 ; r < n ; r++){
            if(isSafe(r, col, board , n)){
                board[r][col] = 'Q';

                solve( col + 1 , board ,  n);


                board[r][col] = '.';


            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n , string(n , '.'));

        solve(0 , board ,  n);

        return ans;
    }
};