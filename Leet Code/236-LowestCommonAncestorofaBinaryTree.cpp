class Solution {
    public:
    TreeNode* help(TreeNode* root, TreeNode* p, TreeNode* q){
         if(root == NULL) return NULL;
            if(root ==p || root == q) return root;
            TreeNode* lef = lowestCommonAncestor(root->left,p,q);
            TreeNode* rig = lowestCommonAncestor(root->right,p,q);
           if(lef!=NULL && rig!=NULL) return root;
           else if(lef!=NULL) return lef;
            else if(rig!=NULL) return rig;
            return NULL;
    }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           return help(root,p,q);
        }
    };