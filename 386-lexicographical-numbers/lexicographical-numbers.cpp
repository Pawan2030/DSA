class Solution {
public:
    
    void solve(int s, int n, vector<int> &res){

        if(s > n) return;

        res.push_back(s);

        for(int i=0; i<=9; i++){

            int val = s*10 + i;

            solve(val, n, res);
        }

    }


    vector<int> lexicalOrder(int n) {
        
        vector<int> res;

        for(int i=1; i<=min(n , 9); i++){
            solve(i, n, res);
        }
        return res;
    }
};