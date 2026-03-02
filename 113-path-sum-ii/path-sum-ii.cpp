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
    void solve(TreeNode* root, int curr , int targetSum , vector<vector<int>> &ans , vector<int> &cur){
        if(!root){
            return;
        }

        curr += root -> val;

        cur.push_back(root -> val);


        if(!root -> left && !root -> right && curr == targetSum){
            ans.push_back(cur);
        }
        else{
            solve(root -> left , curr , targetSum , ans , cur);
            solve(root -> right , curr , targetSum , ans , cur);

        }

        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(root , 0 , targetSum , ans , curr);
        return ans;
    }
};