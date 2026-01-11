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
    
    pair<int,int> solve(TreeNode* root){

        if(!root) return {0,0};

        auto left  = solve(root->left);
        auto right = solve(root->right);

        int val1 = root->val + left.second + right.second;
        int val2 = max(left.first , left.second) + max(right.first , right.second);

        return {val1 , val2};
    }

    int rob(TreeNode* root) {
        
        int ans1 = solve(root).first;
        int ans2 = solve(root).second;

        return max(ans1 , ans2);
    }
};