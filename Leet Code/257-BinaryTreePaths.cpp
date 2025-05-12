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
    void dfs(vector<string>&ans,TreeNode* root,string s){
        if(!root->right&&!root->left){
            ans.push_back(s);
            return;
        }
        if(root->left){
            dfs(ans,root->left,s+"->"+to_string(root->left->val));
        }
        if(root->right) dfs(ans,root->right,s+"->"+to_string(root->right->val));
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root)return ans;
        dfs(ans,root,to_string(root->val));
        return ans;
        
    }
};