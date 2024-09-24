class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<string,int> mp1,mp2;
        
        for(int i=0; i<arr1.size(); i++){
            
            string p =  to_string(arr1[i]); 
            
            for(int j=0; j<p.size(); j++)
            {
                mp1[p.substr(0,j+1)]++;
            }
        }
        
        for(int i=0; i<arr2.size(); i++){
            
            string p =  to_string(arr2[i]); 
            
            for(int j=0; j<p.size(); j++)
            {
                mp2[p.substr(0,j+1)]++;
            }
        }
        
        int ans = 0;
        
        for(auto st : mp1){
            
            if(mp2[st.first] >= 1)
            {
               ans = max(ans , (int)(st.first).size());  
            }
        }
        return ans;
    }
};