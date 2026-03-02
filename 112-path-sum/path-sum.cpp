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
    bool solve(TreeNode* root, int curr , int targetSum){
        if(!root){
            return false;
        }

        curr += root -> val;

        if(!root -> left && !root -> right){
            return curr == targetSum;
        }


        return solve(root -> left , curr , targetSum ) || solve(root -> right , curr , targetSum );
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root , 0 , targetSum);
    }
};