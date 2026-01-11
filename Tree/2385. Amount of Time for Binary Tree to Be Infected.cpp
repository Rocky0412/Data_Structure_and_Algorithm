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
    int height(TreeNode* root){
        return !root ? 0 :1+max(height(root->left),height(root->right));
    }
    int solve(TreeNode* root , int &ans, int start){
        if(!root) return 0;
        if(root->val==start){
            ans=height(root)-1;
            return -1;
        }
        int l=solve(root->left,ans,start);
        int r=solve(root->right,ans,start);
        if(l<0 or r<0) 
        {
            ans=max((abs(l)+abs(r)),ans);
            return min(l,r)-1;
        }
        return 1+max(l,r);
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        solve(root,ans,start);
        return ans;
        
    }
};
