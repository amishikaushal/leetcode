class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }


        int i = 0;
        int sign = 1;

        long res = 0;

        while(i < n && s[i] == ' '){
            i++;
        }

        if(i == n) return 0;

        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        if(i < n && !isdigit(s[i])){
            return 0;
        }

        while(i < n && isdigit(s[i])){
            res = res * 10 + (s[i] - '0');


            if(sign * res <= INT_MIN) return INT_MIN;
            if(sign * res >= INT_MAX) return INT_MAX;

            i++;
        }

        return (int)sign* res;




    }
};