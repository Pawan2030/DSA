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

    void solve(TreeNode* root , int cnt ,int &ans){

        if(!root->left && !root->right){
            ans = max(ans , cnt);
            return;
        }

        if(root->left){
            cout<<"cnt "<<cnt<<endl;
            solve(root->left , cnt+1 , ans);
        }

         if(root->right){
             cout<<"cnt "<<cnt<<endl;
            solve(root->right , cnt+1 , ans);
        }

    }

    int maxDepth(TreeNode* root) {

        if(!root) return 0;

        int cnt = 1;
        int ans = 0;
        solve(root , cnt , ans);
        return ans;
        
    }
};