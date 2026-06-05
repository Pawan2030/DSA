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
    
    int solve(TreeNode* root , int &maxSum){

        if(!root) return 0;

        int l = solve(root->left , maxSum);
        int r = solve(root->right , maxSum);
        
        int case1 = max(l , r) + root->val;
        int case2 = root->val;

        maxSum = max({maxSum , root->val + l + r , case1 , case2});


        return max(case1 , case2);
    }
 
    int maxPathSum(TreeNode* root) {
         
         int maxSum = INT_MIN;
         solve(root , maxSum);
         return maxSum;
    }
};