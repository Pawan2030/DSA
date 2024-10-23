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

    TreeNode* replaceValueInTree(TreeNode* root) {
        
        vector<int> vec;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            int sum = 0;

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
            vec.push_back(sum);
        }

        q.push(root);
        root->val = 0;
        int i = 1;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                TreeNode* top = q.front();
                q.pop();

                int sibling = 0;

                if(top->left){
                    sibling += top->left->val;
                }
                if(top->right){
                    sibling += top->right->val;
                }

                if(top->left){
                    top->left->val = vec[i] - sibling;
                    q.push(top->left);
                }

                if(top->right){
                    top->right->val = vec[i] - sibling;
                    q.push(top->right);
                }  
            }
            i++;
        }

        return root;
    }
};