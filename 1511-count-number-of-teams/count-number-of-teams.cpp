class Solution {
public:
    
    pair<int,int> left(int val , int n , vector<int>& rat){
        
        int small  = 0;
        int greater = 0;

        for(int i = 0; i<n; i++){

            if(rat[i] < val){
                small++;
            }
            else if(rat[i] > val){
               greater++;
            }
        }

        return {small , greater};
    }

    pair<int,int> right(int val , int idx , int n , vector<int>& rat){
        
        int small  = 0;
        int greater = 0;

        for(int i = idx; i<n; i++){

            if(rat[i] < val){
                small++;
            }

            else if(rat[i] > val){
               greater++;
            }
        }

        return {small , greater};
    }




    int numTeams(vector<int>& rating) {

        int teams = 0;
        int n = rating.size();

        for(int i=0; i<n; i++){
           
           auto [ leftSmaller   ,  leftGreater]  = left(rating[i] , i , rating);
           auto [ rightSmaller ,  rightGreater] = right(rating[i] , i+1 , n , rating);

           teams += (leftSmaller * rightGreater);
           teams += (leftGreater * rightSmaller);
        }

        return teams;
    }
};