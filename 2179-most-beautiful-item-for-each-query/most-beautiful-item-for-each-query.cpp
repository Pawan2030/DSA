class Solution {
public:
    
    int n1;

    int BinarySearch(vector<vector<int>>& items , int q){

        int s = 0;
        int e = items.size()-1;
        int maxBeauty = 0;

        while(s <= e){
            
            int mid = s + (e-s)/2;

            if(items[mid][0] <= q){
                maxBeauty = max(maxBeauty,items[mid][1]);
                s = mid+1;
            }
            else{
                e = mid-1;
            }

        } 
        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

      vector<int> res;
      n1 = items.size();
      int n2 = queries.size();

      sort(begin(items) , end(items));

      int seen = 0;

      for(int i=0; i<items.size(); i++){
         seen = max(seen , items[i][1]);
         items[i][1] = seen; 
      }
    
      for(int q : queries){
         int maxBeauty = BinarySearch(items , q);
         res.push_back(maxBeauty);
      }
      return res;  
    }
};