class Solution {
public:
    
    int n;
    int t[1001][1001];
   
    int solve(int idx , vector<vector<int>>& books , int remain , int self , int maxH){

        if(idx >= n){
            return t[idx][remain] = maxH;
        }

        if(t[idx][remain] != -1){
            return t[idx][remain];
        }

        int keep = INT_MAX;
        int skip = INT_MAX;

        if(remain >= books[idx][0]){
            keep = solve(idx+1 , books , remain-books[idx][0] , self , max(books[idx][1] , maxH));
        }

            skip = maxH + solve(idx+1 , books , self-books[idx][0] , self , books[idx][1]);
         
            return t[idx][remain] = min(keep , skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        n = books.size();
        int remain = shelfWidth;
        int maxH = 0;
        memset(t , -1 , sizeof(t));

        return solve(0 , books , remain , shelfWidth , maxH);
        
    }
};