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
                                                                   
    int widthOfBinaryTree(TreeNode* root) {
         
         if(!root) return 0;
         queue<pair<TreeNode*,long long>> q;
         q.push({root,0});
         long long dist = INT_MIN;

         while(!q.empty()){

            int size = q.size();
            
            long long d1 = q.front().second;
            long long d2 = q.back().second;

            dist = max(dist , d2-d1+1);

            while(size--){

                TreeNode* node = q.front().first;
                long long len        = q.front().second;
                q.pop();

                long long idx = len - d1;

                if(node->left){
                    q.push({node->left,2*idx+1});
                }

                if(node->right){
                    q.push({node->right,  (long long)2*idx+2});
                }
            }

         }
         
         return dist;
    }
};