class Solution {
public:
    
    bool solve(int num , int p){

        if(num == 0) return true;

        if(pow(3 , p) > num) return false;

        bool take = solve(num-pow(3 , p) , p+1);

        bool skip = solve(num , p+1);

        return take || skip ;
    }


    bool checkPowersOfThree(int n) {

        return solve(n , 0);
        
    }
};