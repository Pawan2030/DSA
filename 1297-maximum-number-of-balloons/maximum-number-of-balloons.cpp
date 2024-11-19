class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        vector<int> vec(26 , 0);

        for(char ch : text){
            vec[ch-'a']++;
        }

        string st = "balloon";
        int res = INT_MAX;

        for(char ch : st){

            if(ch != 'l' && ch != 'o' && vec[ch-'a'] > 0){
               res = min(res , vec[ch-'a']);
            }
            else if(ch == 'l' || ch == 'o'){
               res = min(res , vec[ch-'a']/2);
            }
            else{
                //cout<<ch<<endl;
                 res = 0;
            }
        }
        return res;
    }
};