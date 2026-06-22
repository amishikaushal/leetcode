class Solution {
public:
    bool solve(int i , int j , vector<vector<char>>& board, string word , int ind , int n , int m ){
        if(ind == word.size()){
            return true;
        }

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[ind]){
            return false;
        }

        char c = word[ind];

        board[i][j] = '.';

        bool l = solve(i , j + 1 , board , word , ind + 1 , n , m);
        bool r = solve(i , j - 1 , board , word , ind + 1 , n , m);
        bool u = solve(i - 1 , j , board , word , ind + 1 , n , m);
        bool d = solve(i + 1, j  , board , word , ind + 1 , n , m);


        board[i][j] = c;

        return l || r || u || d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board[0].size();
        int n = board.size();


        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(solve(i , j , board , word , 0 , n , m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};