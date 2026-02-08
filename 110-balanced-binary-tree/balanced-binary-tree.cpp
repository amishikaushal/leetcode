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
    int solve(TreeNode* root , bool& isBal){
        if(!root){
            return 0;
        }


        int l = solve(root -> left , isBal);
        int r = solve(root -> right , isBal);

        if(abs(l - r) > 1){
            isBal = false;
        }

        return 1 + max(l , r);
    }
    bool isBalanced(TreeNode* root) {
        bool istrue = true;

        solve(root , istrue);
        return istrue;
    }
};