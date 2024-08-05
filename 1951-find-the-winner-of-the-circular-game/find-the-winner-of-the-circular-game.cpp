class Solution {
public:

    void solve(vector<int> &vec ,int idx , int k , int &ans){

        //base case
        if(vec.size() == 1){
            ans = vec[0];
            return;
        }
        
        idx = (idx+k)%(vec.size());
        vec.erase(vec.begin()+idx);
        solve(vec , idx , k , ans);
    }

    int findTheWinner(int n, int k) {
        
        vector<int> vec(n);

        for(int i=0; i<n; i++){
            vec[i] = i+1;
        }

        int ans;
        solve(vec , 0 , k-1 , ans);
        return ans;
    }
};