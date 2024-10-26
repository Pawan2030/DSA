class Solution {
public:
    int N; // total nodes
    vector<vector<int>> lv; // this will store level and it's maximum heights and only 2 of its point
    vector<int> nlv; // this will store value of nodes level 
    vector<int> nheg; // this will store height of n node
    // this function will init all above vectors recursively
    int trverse(TreeNode* r,int l){
        if(r == NULL) return 0;
        // find N 
        N = max(N,r->val);
        // nlv array will contain r->val level
        nlv[r->val] = l;
        // call for left and right
        int lt = trverse(r->left,l+1);
        int rt = trverse(r->right,l+1);
        // nheg will store height of nth node as root node
        nheg[r->val] = max(lt,rt);
        // push this node in this level
        lv[l].push_back(nheg[r->val]);
        if(lv[l].size() == 3){
            // find min and remove it
            int mi = min({lv[l][0],lv[l][1],lv[l][2]});
            if(lv[l][0] == mi) swap(lv[l][2],lv[l][0]);
            else if(lv[l][1] == mi) swap(lv[l][2],lv[l][1]);
            lv[l].pop_back();
        }
        return nheg[r->val] + 1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // initalizing size of vectors
        lv.resize(1e5);
        nheg.resize(1e5+1,0);
        nlv.resize(1e5+1,0);
        // we can store tree node with their value
        N = 0;
        nheg[0] = -1;
        trverse(root,0); // fill all vectors
        vector<int> t(N+1,0); // store values of height if every node is deleted one time
        vector<int> ans(queries.size(),0);
        for(int i=1;i<=N;i++){
            // try removing i
            // we are going to search that level
            if(nlv[i] == 0) continue; // if i is root node
            int new_maxh = -1; // we have to find new max height
            bool cnt = 1; // if we have same value for 2 time then avoid only one time
            // traverse level of i'th node
            for(int j : lv[nlv[i]]){
                if(j == nheg[i] && cnt){ cnt = 0; continue;}
                new_maxh = max(new_maxh, j);
            }
            // if new max is -1 means no other node at this level so this means we can only have tree height 
            // if we found another max then add that max height to this level
            t[i] = new_maxh == -1 ? nlv[i] - 1 : nlv[i] + new_maxh;
        }
        // Now just fill answer for queries
        for(int i=0;i<queries.size();i++){
            ans[i] = t[queries[i]];
        }
        return ans;
    }
};