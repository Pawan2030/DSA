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
    
    void makeMap(TreeNode* root, unordered_map<int , vector<int>>& mp){
        
        queue<TreeNode*> q;
        unordered_set<int> visited;
        q.push(root);
        //visited.insert(root->val);

        while(!q.empty()){

            TreeNode* front = q.front();
            q.pop();

            // if(visited.count(front->val)){
            //     continue;
            // }

            if(front->left){
                mp[front->left->val].push_back(front->val);
                mp[front->val].push_back(front->left->val);
                q.push(front->left);
            }

            if(front->right){
                mp[front->right->val].push_back(front->val);
                mp[front->val].push_back(front->right->val);
                q.push(front->right);
            }

            visited.insert(front->val);
        }
    }

    int Burning(int &st,  unordered_map<int , vector<int>> &mp){

        queue<int> q;
        int minTime = 0;
        q.push(st);
        unordered_set<int> visited;
        visited.insert(st);

        while(!q.empty()){

            int n = q.size();

            while(n--){

                int f = q.front();
                q.pop();

                for(int it : mp[f]){
                    
                    if(!visited.count(it)){
                        q.push(it);
                        visited.insert(it);
                    }
                }
            }
            minTime++;
        }

        return minTime-1;
    }

    int amountOfTime(TreeNode* root, int start) {
        
        // child to parents map
        unordered_map<int , vector<int>> mp;
        makeMap(root,mp);

        //main logic
        return Burning(start,mp);

    }
};