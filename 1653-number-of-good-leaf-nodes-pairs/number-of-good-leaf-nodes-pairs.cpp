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

    void graph(TreeNode* root , TreeNode* prev , unordered_map<TreeNode* , vector<TreeNode*>>& adj , unordered_set<TreeNode*>& st){

        if(!root){
            return;
        }

        if(!root->left && !root->right){
            st.insert(root);
        }

        if(prev){
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }

        graph(root->left , root , adj , st);
        graph(root->right , root , adj , st);
        
    }

    int countPairs(TreeNode* root, int distance) {

        unordered_map<TreeNode* , vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;

        graph(root , NULL , adj , st);

        int count = 0;

        for(auto &leaf :  st){

            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);

            for(int level = 0;  level <= distance ; level++){

                int size = q.size();

                while(size--){

                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr != leaf && st.count(curr)){
                        count++;
                    }

                    for(auto &node : adj[curr]){
                        if(!visited.count(node)){
                            q.push(node);
                            visited.insert(node);
                        }
                    }

                }
            }
        }
        return count/2;
    }
};