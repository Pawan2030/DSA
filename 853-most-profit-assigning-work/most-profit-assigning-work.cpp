class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>> vec;
        int n = difficulty.size();

        for(int i=0; i<n; i++){

            vec.push_back({difficulty[i] , profit[i]});
        }

        // auto comp = [&](pair<int,int> p1 , pair<int,int> p2){
        //     return p1.first > p2.first;
        // };

        sort(begin(vec) , end(vec));
       
       //obseravation 
        for(int i=1; i<n; i++){
            vec[i].second = max(vec[i-1].second , vec[i].second);
        }


        int maxprofit = 0;

        for(int i=0; i<worker.size(); i++){

         int work = worker[i]; 
         int s = 0;
         int e = n-1;
         int temp ;

         while(s <= e){
           
           int mid = s + (e-s)/2;

           if(work >= vec[mid].first){
              temp = vec[mid].second;
              s = mid+1;
           }
           else{
               e = mid-1;
           }

           //condition to get profit on worker i
          
         }
           if(e >= 0){
               maxprofit += temp;
           }

        }
        return maxprofit;
    }
};