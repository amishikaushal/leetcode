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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode* , unsigned long long>> q;

        int maxi = 0;

        q.push({root , 0});

        while(!q.empty()){
            int s = q.size();

            unsigned long long fr = q.front().second;
            unsigned long long  b = q.back().second;

            maxi = max(maxi , (int)(b - fr + 1));


            for(int i = 0; i < s ; i++){
                auto [node , pos] = q.front();
                q.pop();


                if(node -> left) q.push({node -> left , 2 * pos});
                if(node -> right) q.push({node -> right , 2 * pos + 1});
            }
        }
        return maxi;
    }
};