class Solution {
public:
    
    bool check_Sum_Equal_To_i(int idx , int sum , int equalSum , string &st){

        if(idx == st.length()){
            return sum == equalSum;
        }

        if(sum > equalSum) return false;

       // bool possible = false;

        for(int len = 1; len+idx <= st.length(); len++){
            
            string sub = st.substr(idx , len);
            int val =  stoi(sub);
            bool possible = check_Sum_Equal_To_i(idx+len , sum + val, equalSum , st);
            if(possible) return true;
        }
 
        return false;
    }



    int punishmentNumber(int n) {
        
        int toalSum = 0;

        for(int i=1; i<=n; i++){

            int sq = i*i;
            string st = to_string(sq);

            if(check_Sum_Equal_To_i(0 , 0 , i , st)){
                toalSum += sq;
            }
        }

        return toalSum;
    }
};