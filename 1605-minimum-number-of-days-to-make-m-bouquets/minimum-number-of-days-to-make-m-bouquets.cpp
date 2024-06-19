class Solution {
public:
    
    bool isPossible(int day , vector<int>& arr , int k , long long total){

        int sum = 0;
        int cont = 0;

        for(int i = 0; i<arr.size() ; i++){
             
             if(arr[i] <= day){
                 cont++;
             }
             else{
                cont = 0;
             }

             if(cont == k){
                sum += cont;
                cont = 0;
             }

             if(sum == total){
                return true;
             }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        long long total = m*1LL*k;

        if(n < total){
            return -1;
        }

        int s = 0;
        int e = *max_element(begin(bloomDay) , end(bloomDay));
        cout<<"max day"<<e<<endl;
        int ans = -1;

        while(s <= e){

            int mid = s + (e-s)/2;

            if(isPossible(mid , bloomDay , k , total)){
                ans = mid; 
                cout<<"FINAL"<<ans<<endl;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};