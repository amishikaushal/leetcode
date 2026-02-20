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
    bool is(TreeNode* leftii , TreeNode* rightyy){
        if(leftii == nullptr && rightyy == nullptr){
            return true;
        }

        if(leftii == nullptr || rightyy == nullptr ){
            return false;
        }

        if(leftii -> val != rightyy -> val){
            return false;
        }

        return is(leftii -> left , rightyy -> right) && is(leftii -> right , rightyy -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return is(root -> left , root -> right);
        
    }
};