class Solution {
public:
    
    int check(int k, vector<int>& A, vector<int>& B){
        
        int com = 0;
        unordered_map<int,int> mp;
        
        for(int i=0; i<=k; i++){
            mp[A[i]]++;
        }

        for(int i=0; i<=k; i++){

            if(mp.find(B[i]) != mp.end()){
                com++;
            }
        }
        return com;
    }

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> common(n);
        // sort(begin(A),end(A));
        // sort(begin(B),end(B));

        for(int i=0; i<n; i++){  
            int com = check(i,A,B);
            common[i] = com;
        }
        return common;
    }
};