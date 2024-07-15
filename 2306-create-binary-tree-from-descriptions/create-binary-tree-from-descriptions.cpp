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

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_set<int> st;
        unordered_map<int , TreeNode*> mp;

        for(auto vec : descriptions){

            int par    = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];
             
    
            if(mp.find(par) == mp.end()){    
                mp[par] = new TreeNode(par);
            }
            if(mp.find(child) == mp.end()){    
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1){
                mp[par]->left = mp[child];
            }
            else{
                mp[par]->right = mp[child];
            }
            st.insert(child);
         }

        for(auto it : descriptions){
            
            int val = it[0];

            if(st.find(val) == st.end()){
                return mp[val];
            }
         }

        return NULL;
    }
};