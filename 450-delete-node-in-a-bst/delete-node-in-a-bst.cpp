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
    TreeNode* findmin(TreeNode* root){
        TreeNode* curr = root;

        while(curr -> left){
            curr = curr -> left;
        }

        return curr;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }
        if(root -> val > key){
            root -> left = deleteNode(root -> left , key);
        }
        else if(root -> val < key){
            root -> right = deleteNode(root -> right , key);
        }
        else{
            TreeNode* temp = root;

            if(temp -> left == nullptr){
                return temp -> right;
                delete temp;
            }
            else if(temp -> right == nullptr){
                return temp -> left;
                delete temp;
            }
            else{
                TreeNode* curr = findmin(root -> right);

                root -> val = curr -> val;

                root -> right =  deleteNode(root -> right , curr -> val);
            }
        }
         return root;
    }
};