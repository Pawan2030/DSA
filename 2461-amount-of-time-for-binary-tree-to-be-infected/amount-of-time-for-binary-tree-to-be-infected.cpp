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
    int solve(TreeNode* root, int start , int &res){

        if(!root) return 0;

        int l = solve(root->left , start , res);
        int r = solve(root->right , start , res);

        if(root->val == start){
            res = max(l , r);
            return -1;
        }

        if(l < 0 || r < 0){
             
            int add = abs(l) + abs(r);
            res = max(res , add);
            return min(l , r) - 1;
        }

       return max(l , r) + 1;
    }

    int amountOfTime(TreeNode* root, int start) {
         
         int res;
         solve(root , start , res);
         return res;
    }
};