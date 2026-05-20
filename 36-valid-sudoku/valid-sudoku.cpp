class Solution {
public:
    bool isValid(vector<vector<char>>& board , int row , int col , char c){
        for(int i = 0; i < 9; i++){
            if(i != row && board[i][col] == c){
                return false;
            }
        }

         for(int i = 0; i < 9; i++){
            if(i != col && board[row][i] == c){
                return false;
            }
        }


        for(int i = 0; i < 9; i++){
            int rowBoard = 3 * (row/3) + i / 3;
            int colBoard = 3 * (col/3) + i % 3;

             if((rowBoard != row || colBoard != col) && board[rowBoard][colBoard] == c){
                return false;
            }


        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9 ; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(!isValid(board , i , j , board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};