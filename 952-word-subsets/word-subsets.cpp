class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        //so i am thinking like this 

        int n2 = words2.size();
        int n1 = words1.size();
        vector<string> res;
        int letterCount = 0;

        //count each letter and his freq of b -> words2
        vector<int> cnt2(26,0);
        for(int i=0; i<n2; i++){

            string word = words2[i];
            vector<int> temp(26 , 0);

            for(char ch : word){
                temp[ch-'a']++;
            }

            for(int j=0; j<26; j++){
                cnt2[j] = max(cnt2[j] , temp[j]);
            }
        }

        for(int i=0; i<26; i++){
            letterCount += cnt2[i];
        }

        for(int i=0; i<n1; i++){

            string isUniversal = words1[i]; //amazone
            vector<int> cnt1(26,0);
            for(char ch : isUniversal){
                cnt1[ch-'a']++;
            }
            
            int comp = 0;
            for(int k=0; k<26; k++){
                if(cnt1[k] >= cnt2[k]){
                    comp += cnt2[k];
                }
            }

            if(comp == letterCount){
                res.push_back(isUniversal);
            }

        }

        return res;
    }
};