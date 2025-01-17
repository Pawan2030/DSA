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
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();

            while(size > 0){
                
                TreeNode* front = q.front();
                q.pop();

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }

                if(size == 1){
                    res.push_back(front->val);
                }

                size -= 1;
            }

        }

        return res;
    }
};