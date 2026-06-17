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
    TreeNode* solve(vector<int>& preorder, int pres , int prend, vector<int>& inorder, int ins , int inend , map<int , int> &mpp){
        if(pres > prend || ins > inend){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pres]);

        int inRoot = mpp[root -> val];

        int lefti = inRoot - ins;

        root -> left = solve(preorder , pres + 1 , pres + lefti , inorder , ins , inRoot - 1 , mpp);


        root -> right = solve(preorder , pres + lefti + 1  , prend , inorder ,  inRoot + 1 , inend, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int , int> mpp;
        int n = inorder.size();

        for(int i = 0; i < n; i++){
            mpp[inorder[i]] = i;
        }


        return solve(preorder , 0 , n -1 , inorder , 0 , n -1 , mpp);

    }
};