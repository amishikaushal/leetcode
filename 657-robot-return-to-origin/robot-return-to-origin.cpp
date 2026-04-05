class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0 , y = 0;

        for(char it : moves){
            if(it == 'U') x++;
            else if(it == 'D') x--;
            else if(it == 'R') y++;
            else y--;
        }

        return (x == 0 && y == 0);
    }
};