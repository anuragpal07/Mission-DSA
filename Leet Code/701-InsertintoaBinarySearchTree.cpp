class Solution {
    public:
     TreeNode* insertIntoBST(TreeNode* &root, int &val) {
            if (!root) {
                TreeNode* newNode = new TreeNode(val);
                return newNode;
            }
            if (val < root->val) {
                if (!root->left) {
                    TreeNode* newNode = new TreeNode(val);
                    root->left = newNode;
                }
                else {
                    insertIntoBST(root->left, val);
                }
            }
            else {
                if (!root->right) {
                    TreeNode* newNode = new TreeNode(val);
                    root->right = newNode;
                }
                else {
                    insertIntoBST(root->right, val);
                }
            }
            return root;
        }
    };