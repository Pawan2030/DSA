class Solution {
public:
    
    int n;
    long long t[2][100001];

    long long solve(int drink , int i , vector<int>& A , vector<int>& B){

        if(i >= n) return 0;

        if(t[drink][i] != -1){
            return t[drink][i]; 
        }

        long long maxiA = INT_MIN , maxiB = INT_MIN;
        
        if(drink == 0){
           
           maxiA = A[i] + max(solve(0 , i+1 , A , B) , solve(1 , i+2 , A , B));
        }
        else{

          maxiB = B[i] + max(solve(1 , i+1 , A , B) , solve(0 , i+2 , A , B));
        }
        
        return t[drink][i] = max(maxiA , maxiB);
    }
 
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        
        n = energyDrinkA.size();
        memset(t , -1 , sizeof(t));
        long long a = solve(0 , 0 , energyDrinkA , energyDrinkB);
        long long b = solve(1 , 0 , energyDrinkA , energyDrinkB); // drink , i , arr , arr

        return max(a , b);
    }
};