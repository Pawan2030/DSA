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

    TreeNode* solve(TreeNode* root , unordered_set<int>& st , vector<TreeNode*>& arr){

        if(!root) return NULL;

        root->left  = solve(root->left  , st , arr);
        root->right = solve(root->right , st , arr);

        if(st.count(root->val)){
             
             if(root->left != NULL){
                arr.push_back(root->left);
             }

             if(root->right != NULL){
                arr.push_back(root->right);
             }

            return NULL;

        }

         return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        unordered_set<int> st;

        for(int num : to_delete){
            st.insert(num);
        }

        vector<TreeNode*> arr;

        if(solve(root , st , arr)){
            arr.push_back(root);
        }

        return arr; 
    }
};