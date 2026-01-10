class Solution {
public:
    TreeNode* solve(vector<TreeNode*>& ans,TreeNode* root,set<int>st){
        if(!root) return NULL;
        TreeNode* lr=solve(ans,root->left,st);
        TreeNode* rr=solve(ans,root->right,st);
        if(st.count(root->val)){
            if(lr){
                ans.push_back(lr);
            }
            if(rr){
                ans.push_back(rr);
            }
            return NULL;
        }
        root->left=lr;
        root->right=rr;
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>st(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;
        TreeNode* p=solve(ans,root,st);
        if(p){
            ans.push_back(p);
        }
        return ans;

    }
};