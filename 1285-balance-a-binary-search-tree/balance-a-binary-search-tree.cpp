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

    TreeNode* leftTreeCreation(vector<int>& arr , int s , int e){
         
         if(s > e) return NULL;

        int mid = s + (e-s)/2;

        TreeNode* newRoot = new TreeNode(arr[mid]);

        newRoot->left  = leftTreeCreation(arr , s , mid-1);
        newRoot->right = leftTreeCreation(arr , mid+1 , e);

        return newRoot;
    }

  
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> arr;
        inorder(root , arr);
        
        //createbalance tree

        int n = arr.size();
        int mid = n/2;

        TreeNode* newRoot = new TreeNode(arr[mid]);

        newRoot->left = leftTreeCreation(arr , 0 , mid-1);
        newRoot->right = leftTreeCreation(arr , mid+1 , n-1);

        return newRoot;
    }
};