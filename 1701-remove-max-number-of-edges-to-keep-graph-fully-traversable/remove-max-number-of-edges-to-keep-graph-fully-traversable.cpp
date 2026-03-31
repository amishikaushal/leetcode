class DSU{
public:
    vector<int> parent;
    int components; 

    DSU(int n) {
        parent.resize(n + 1);
        components = n;

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

  
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

   
    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return false; 

        parent[pb] = pa;
        components--; 
        return true;
    }
};



class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n); 
        DSU bob(n);   
        
        int removed = 0;

     
        for (auto &e : edges) {
            if (e[0] == 3) {

                bool a = alice.unite(e[1], e[2]);
                bool b = bob.unite(e[1], e[2]);

               
                if (!a && !b)
                    removed++;
            }
        }

       
        for (auto &e : edges) {
            if (e[0] == 1) {
          
                if (!alice.unite(e[1], e[2]))
                    removed++;
            }
        }

        for (auto &e : edges) {
            if (e[0] == 2) {
                if (!bob.unite(e[1], e[2]))
                    removed++;
            }
        }

       
        if (alice.components != 1 || bob.components != 1)
            return -1;

        return removed;
    }
};