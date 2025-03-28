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

void swap(TreeNode* A, TreeNode* B)
{
    int tmp = A->val;
    A->val = B->val;
    B->val = tmp;
}

    int minimumOperations(TreeNode* root) {
  
      queue<TreeNode*>q;
      q.push(root);
      int res = 0;

      while(!q.empty())
      {
          int n = q.size();
           vector<TreeNode*>v;

          for(int i = 0; i < n ; ++i)
          {
              auto temp = q.front();
              q.pop();

              if(temp->left != NULL) q.push(temp->left);
              if(temp->right != NULL) q.push(temp->right);

              v.push_back(temp);
          }

          vector<int>copy;
          unordered_map<int,int>mpp;

          for(auto it : v) copy.push_back(it->val);
          
          
          sort(copy.begin(), copy.end());

          
          for(int i = 0;i < copy.size(); ++i) mpp[copy[i]] = i;
          
         
          for(int i = 0; i < v.size(); ++i)
          {
              if(mpp[v[i]->val] != i)
              {
                 swap(v[i], v[mpp[v[i]->val]]);
                 res++;
                 i--;
              }
          }

      }

      return res;  
    }
};
