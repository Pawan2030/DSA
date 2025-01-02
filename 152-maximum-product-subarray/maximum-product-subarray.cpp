class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int l = 1;
        int r = 1;
        int res = INT_MIN;

        for(int i=0; i<n; i++){

            l = l == 0 ? 1 : l;
            r = r == 0 ? 1 : r;
             
            l *= nums[i];
            r *= nums[n-i-1];
            res = max({res , l , r , nums[i]});
            
        }

        return res;
    }
};

//broot force->

//-> try through every subset and track the max product from every subset
// time complexity->>>>> o(n*n)

/*

 int res = INT_MIN;
 int n = nums.size();
        for(int i=0; i<n; i++){
            long long pro = 1;
            for(int j=i; j<n; j++){
               pro *= nums[j];
               res = fmax(res,pro);
            }
        }
    return res;

*/