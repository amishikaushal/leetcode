class Solution {
public:
    bool search(int i , int j , vector<vector<char>>& board, string word , int ind , int n , int m){
        if(ind == word.length()){
            return true;
        }

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[ind]) return false;


        char c = board[i][j];
        board[i][j] = '.';

        int l =search(i , j + 1 , board , word , ind + 1 , n , m);
        int r = search(i  , j - 1 , board , word , ind + 1 , n , m);
        int t = search(i -1 , j , board , word , ind + 1 , n , m);
        int b = search(i + 1 , j , board , word , ind + 1 , n , m);

        board[i][j] = c;

        return l || r || t || b;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();


        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(search(i , j , board , word , 0 , n , m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};