/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(!root){
            return {};
        }

        vector<vector<int>> ans;

        queue<pair<TreeNode* , pair<int , int>> > q;

        map<int , vector<pair< int , int>>> mpp;

        TreeNode* curr = root;

        q.push({curr , {0 , 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;


            mpp[y].push_back({x , node -> val});

            if(node -> left){
                q.push({node -> left , {x + 1 , y -1}});
            }

            if(node -> right){
                q.push({node -> right , {x + 1 , y + 1}});
            }
        }


        for(auto &[it , row] : mpp){
            vector<pair<int , int>> row_nodes = row;


            sort(row_nodes.begin(), row_nodes.end());


            vector<int> cols;

            for(auto &it : row_nodes){
                cols.push_back(it.second);
            }

            ans.push_back(cols);
        }
        return ans;


    }
};