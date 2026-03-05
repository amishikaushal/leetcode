class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int>> q;
        q.push({beginWord , 1});

        unordered_set<string> seen(wordList.begin() , wordList.end());
         if(seen.find(endWord) == seen.end()){
            return 0;
        }

        seen.erase(beginWord);

        while(!q.empty()){
            auto [word , steps] = q.front();
            q.pop();


            if(word == endWord){
                return steps;
            }

            for(int i = 0 ; i < word.length() ; i++){
                char org = word[i];

                for(char c = 'a' ; c <= 'z' ; c++){
                    word[i] = c;

                    if(seen.find(word) != seen.end()){
                        q.push({word , steps + 1});
                        seen.erase(word);
                    }
                }

                word[i] = org;

            }

        }
        return 0;
    }
};