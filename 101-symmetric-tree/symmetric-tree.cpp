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
    
    bool solve(TreeNode* root1, TreeNode* root2){
         
    
        if(root1 == NULL  && root2 == NULL) return true;
        if(root1 == NULL  || root2 == NULL) return false;

        // cout<<"root1-> "<<root1->val<<endl;
        // cout<<"root2-> "<<root2->val<<endl;
        
        if(root1->val != root2->val) return false;
        
        bool l = solve(root1->left  , root2->right);
        bool r = solve(root1->right , root2->left);
        
        return l && r;
    }


    bool isSymmetric(TreeNode* root) {
        
        return solve(root->left , root->right);
    }
};