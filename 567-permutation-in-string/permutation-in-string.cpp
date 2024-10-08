class Solution {
public:

    bool compare(vector<int>& freq1 , vector<int>& freq2){

        for(int i=0; i<26; i++){

            if(freq1[i] != freq2[i]) return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) return false;

        vector<int> freq1(26,0);
    
        for(char ch : s1){
            freq1[ch-'a']++;
        }

        int i = 0;
        int j = 0;
        vector<int> freq2(26,0);

        while(j < n2){
            
            freq2[s2[j] - 'a']++;

            while(j-i+1 > n1){
               freq2[s2[i] - 'a']--;
               i++;
            }

            if(j-i+1 == n1){

                bool res = compare(freq1 , freq2);

                if(res) return true;
            }

            j++;
        }

        return false;
    }
};