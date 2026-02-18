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
    
    string solve(TreeNode* node){
        
        if(node == NULL){
            return ",null";
        }

        string st = "," + to_string(node->val);

        st += solve(node->left);
        st += solve(node->right);

        return st;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        string s1 = solve(root);
        string s2 = solve(subRoot);

        return s1.find(s2) != string :: npos;
    }
};