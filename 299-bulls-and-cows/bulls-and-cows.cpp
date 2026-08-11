class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        int cow = 0;
        int bulls = 0;


        vector<int> freqSec(10 , 0);
        vector<int> freqGuess(10 , 0);


        for(int i = 0; i < n ; i++){
            if(secret[i] == guess[i]){
                cow++;
            }
            else{
                freqSec[secret[i] - '0']++;
                freqGuess[guess[i] - '0']++;

            }
        }

        for(int i = 0; i <= 9; i++){
            bulls += min(freqSec[i] , freqGuess[i]);
        }


        string ans = to_string(cow) + "A" + to_string(bulls) + "B" ;


        return ans;

    }
};