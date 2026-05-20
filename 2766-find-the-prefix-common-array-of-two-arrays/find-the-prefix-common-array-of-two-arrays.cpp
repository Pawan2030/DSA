class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        int cnt = 0;
        unordered_map<int,int> mp;
        vector<int> ans(n);

        for(int i=0; i<n; i++){

            mp[A[i]]++;

            if(mp[A[i]] == 2){
                cnt++;
            }

            mp[B[i]]++;

            if(mp[B[i]] == 2){
                cnt++;
            }

            ans[i] = cnt;
        }

        return ans;
    }
};