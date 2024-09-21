class Solution {
public:
    
    void solve(int s , int n ,  vector<int>& res){
        
        //base case
        if(s > n) return;
        res.push_back(s);

        for(int app = 0; app<=9; app++){

            int num = s*10+app;

            if(num > n) return;

            solve(num , n , res);
        }

    }

    vector<int> lexicalOrder(int n) {
        
         vector<int> res;

         for(int start = 1; start<=9; start++){
             solve(start , n , res);
         }

         return res;
    }
};