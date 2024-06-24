class Solution {
public:
    
    typedef pair<int , int> p;

    int longestSubarray(vector<int>& nums, int limit) {


        priority_queue<p> maxp;
        priority_queue<p , vector<p> , greater<p>> minp;
        int n = nums.size();

        int maxLength = 0;

        int i = 0;
        int j = 0;

      

        while(i < n){
            
            //push Element in Priority Queue
            maxp.push({nums[i] , i});
            minp.push({nums[i] , i});
           
           int minEle = minp.top().first;
           int maxEle = maxp.top().first;

           //check validity
           while(maxEle - minEle > limit){

              //check from whice pq need to pop
              int max_idx = maxp.top().second;
              int min_idx = minp.top().second;

              if(max_idx > min_idx){

                //pop from minp
                j = min_idx + 1;

                while(minp.top().second < j){
                    minp.pop();
                }

              }
              else{
                 
                 //pop from maxp
                  j = max_idx + 1;

                  while(maxp.top().second < j){
                      maxp.pop();
                  }
              }

              minEle = minp.top().first;
              maxEle = maxp.top().first; 
           }

           //update length

           maxLength = max(maxLength , i-j+1);
           i++;
        }

        return maxLength;
    }
};