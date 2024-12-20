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
    
    void solve(TreeNode* root1 , TreeNode* root2 , int level){

        if(!root1 && !root2) return;

        if(level%2 != 0 && root1 && root2){
            swap(root1->val , root2->val);
        }

        if(root1->left && root2->right){
            solve(root1->left , root2->right , level+1);
        }

        if(root1->right && root2->left){
            solve(root1->right , root2->left , level+1);
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
       
       if(!root) return root;

       int level = 1;
       TreeNode* root1 = root;
       TreeNode* root2 = root; 

       solve(root1->left , root2->right, level);

       return root; 
    }
};