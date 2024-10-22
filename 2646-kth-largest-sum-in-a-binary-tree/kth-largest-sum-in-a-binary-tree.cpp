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

    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        vector<long long> ans;
        queue<TreeNode*> q; 
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            long long sum = 0;

            while(size--){
               
               TreeNode* top = q.front();
               q.pop();

               sum += top->val;

               if(top->left){
                 q.push(top->left);
               }

               if(top->right){
                 q.push(top->right);
               }
            }
            ans.push_back(sum);
        }
        
        if(k > ans.size()){
            return -1;
        }

        sort(rbegin(ans),rend(ans));
        return ans[k-1];
    }
};