class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        vector<int> nums(26 , 0);

        for(int i=0; i<n; i++){
            nums[s[i]-'a'] = i;
        }

        int i =0;
        int j =0;
        vector<int> res;

        while(j<n){

            i = j;
            int lastEle = nums[s[j]-'a'];

            while(j < lastEle){
                j++;
                int temp = nums[s[j]-'a'];
                if(temp > lastEle){
                    lastEle = temp;
                }
            }

            res.push_back(j-i+1);
            j++;
            
        }
        return res;
    }
};