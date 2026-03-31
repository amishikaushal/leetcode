class Solution {
public:
    vector<int> parent;


    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);

        for(int i = 0; i < 26 ; i++){
            parent[i] = i;
        }


        for(auto &it : equations){
            if(it[1] == '='){
                int a = it[0] - 'a';
                int b = it[3] - 'a';
                unite(a, b);
            }
        }


         for (auto &eq : equations) {
            if (eq[1] == '!') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                if (find(a) == find(b)) {
                    return false;
                }
            }
        }

        return true;
    }
};