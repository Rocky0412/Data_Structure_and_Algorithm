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
    void inorder(int &ans,int &prev,TreeNode* root){
        if(!root) return ;
        
        
        inorder(ans,prev,root->left);
        if(prev!=-1){
            int diff=abs(prev - root->val);
            ans=min(ans,diff);
        }
        prev=root->val;
        inorder(ans,prev,root->right);

    }
    int minDiffInBST(TreeNode* root) {
        int prev=-1;
        int ans=INT_MAX;
        inorder(ans,prev,root);
        return ans;
    }
};