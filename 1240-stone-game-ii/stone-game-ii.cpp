class Solution {
public:
    
    int n;
    int t[2][101][101];

    int solveForAlice(int person , int i , int m , vector<int>& piles){

        if(i >= n) return 0;

        if(t[person][i][m] != -1){
            return t[person][i][m];
        }

        int stone = 0;
        int res = person == 0 ? INT_MIN : INT_MAX;

        for(int x = 1; x <= min(2*m , n-i) ; x++){

            stone += piles[i+x-1];

            if(person == 0){ 
               //alice in the game
               
               res = max(res , stone + solveForAlice(1 , i+x , max(m , x) , piles));
            }
            else{
                //bob playing game

                res = min(res , solveForAlice(0 , i+x , max(m , x) , piles));
            }
        }

         return t[person][i][m] = res;
    }

    int stoneGameII(vector<int>& piles) {
        
        //alice = 0
        //bob   = 1
        n = piles.size();
        memset(t , -1 , sizeof(t));

        return solveForAlice(0 , 0 , 1 , piles); // alice turn , idx , m initial val 
    }
};