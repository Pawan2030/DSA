/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
   
   void graph(TreeNode* root , unordered_map<int , vector<int>>& adj){

       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
          
           TreeNode* node = q.front();
           q.pop();

           if(node->left){
             adj[node->val].push_back(node->left->val);
             adj[node->left->val].push_back(node->val);
             q.push(node->left);
           }

            if(node->right){
             adj[node->val].push_back(node->right->val);
             adj[node->right->val].push_back(node->val);
             q.push(node->right);
           }
       }

   }


public:
  
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<int , vector<int>> adj;
        graph(root , adj);

        queue<int> q;
        q.push(target->val);
        unordered_set<int> visited;
        visited.insert(target->val);

        for(int i=0; i<k; i++){
             
            int size = q.size();

            while(size--){

                int top = q.front();
                q.pop();

                for(auto ngr : adj[top]){

                    if(visited.count(ngr) == 0){
                        q.push(ngr);
                        visited.insert(ngr);
                    }
                }

            }
        }

        vector<int> k_level_node;

        while(!q.empty()){
            k_level_node.push_back(q.front());
            q.pop();
        }

        return k_level_node;
    }
};