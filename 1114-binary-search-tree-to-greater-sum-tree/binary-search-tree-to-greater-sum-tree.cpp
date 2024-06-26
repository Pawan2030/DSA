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

    void inorder(TreeNode* root , vector<int>& arr){

        if(root == NULL){
            return;
        }

        inorder(root->left , arr);
        arr.push_back(root->val);
        inorder(root->right , arr);
    }

    void putValue(TreeNode* root , vector<int>& arr , int& idx){
         
        if(!root) return;

        putValue(root->left , arr , idx);

        root->val = arr[idx++];

        putValue(root->right , arr , idx);
    }

    TreeNode* bstToGst(TreeNode* root) {

        vector<int> arr;

        inorder(root , arr);

        for(int i = arr.size() - 2; i >=0 ; i--){

            arr[i] += arr[i+1];
        }

        cout<<arr[0];
        
        int idx = 0;

        putValue(root , arr , idx);

        return root;
        
    }
};