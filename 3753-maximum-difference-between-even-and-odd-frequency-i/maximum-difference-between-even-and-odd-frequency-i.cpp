class Solution {
public:
    int maxDifference(string s) {
        
        int n = s.size();
        int res = INT_MIN;
        vector<int> arr(26 , 0);

        for(int i=0; i<n; i++){
            int val = s[i]-'a';
            arr[val]++;
        }

        for(int i=0; i<26; i++){
            
            if(arr[i]%2 != 0){
                cout<<"odd-> "<<arr[i]<<endl;
               
                for(int j=0; j<26; j++){

                    if(j != i && arr[j] != 0 && arr[j]%2 == 0){
                        cout<<"even-> "<<arr[j]<<endl;
                        int diff = arr[i] - arr[j];
                        res      = max(res , diff);
                        //cout<<res<<endl;
                    }
                }
            }
        }
        return res;
    }
};