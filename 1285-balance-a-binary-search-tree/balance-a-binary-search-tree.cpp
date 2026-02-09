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
    void solve(TreeNode* root , vector<int> &inorder){
        if(!root){
            return;
        }

        solve(root -> left , inorder);
        inorder.push_back(root -> val);
        solve(root -> right , inorder);
    }

    TreeNode* made(vector<int> inorder , int s , int e){
        if(s > e){
            return nullptr;
        }

        int mid = s + (e - s)/2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root -> left = made(inorder , s , mid - 1);
        root -> right = made(inorder , mid + 1 , e);


        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        solve(root , inorder);

        return made(inorder , 0 , inorder.size() - 1);
    }
};