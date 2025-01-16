class Solution {
public:

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int res = 0;
        if(n1%2 != 0){

           for(int i=0; i<n2; i++){
            res ^= nums2[i];
           } 
        }
        
        int val = 0;
        if(n2%2 != 0){

            for(int i=0; i<n1; i++){
                val ^= nums1[i];
            }
        }

        return val^res;
    }
};