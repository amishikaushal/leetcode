/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    
    string serialize(TreeNode* root) {
        if(!root) return "";

    string ans = "";
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if(curr == nullptr) {
            ans += "null ";
            continue;
        }

        ans += to_string(curr->val) + " ";
        q.push(curr->left);
        q.push(curr->right);
    }

    return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         if(data.size() == 0) return nullptr;

        stringstream ss(data);
        vector<string> val;
        string temp;

        while(ss >> temp)
            val.push_back(temp);

        TreeNode* root = new TreeNode(stoi(val[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while(!q.empty() && i < val.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if(val[i] != "null") {
                curr->left = new TreeNode(stoi(val[i]));
                q.push(curr->left);
            }
            i++;

            if(i < val.size() && val[i] != "null") {
                curr->right = new TreeNode(stoi(val[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));