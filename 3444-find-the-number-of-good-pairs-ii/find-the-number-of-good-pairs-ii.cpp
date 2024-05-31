class Solution {
public:

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        unordered_map<int, int> mp;
        long long ans = 0;

        for(int &num : nums2){
            mp[num*k]++;
        }

        for(int &num : nums1){
             
            int val = sqrt(num);

            for(int i=1; i<=val; i++){
                 
                if(num % i != 0) continue;

                    ans += mp[i];
                
                    int val1 = num/i;

                    if(val1 != i){
                        ans += mp[val1];
                    }  
            }
        }
         return ans;
    }
};