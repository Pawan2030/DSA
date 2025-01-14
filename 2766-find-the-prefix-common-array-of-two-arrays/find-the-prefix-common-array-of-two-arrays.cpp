class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

       int n = A.size();
       vector<int> vec(n);
       unordered_map<int,int> mp;
       int cnt = 0;

       for(int i=0; i<n; i++){
          
          mp[A[i]]++;
          if(mp[A[i]] == 2){
             cnt += 1;
          }
 
          mp[B[i]]++;
          if(mp[B[i]] == 2){
             cnt += 1;
          }

          vec[i] = cnt;
       } 

       return vec;
    }
};