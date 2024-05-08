class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();

        priority_queue<pair<int,int>> pq;

        for(int i=0; i<n; i++){
            pq.push({score[i] , i});
        }
       
        vector<string> result(n , "0");
        int cnt = 1;

        while(!pq.empty()){

            auto temp = pq.top();
            pq.pop();

            int idx = temp.second;
    
            if(cnt == 1){
               result[idx] = "Gold Medal" ;
               cnt++;
            }
            else if(cnt == 2){
               result[idx] = "Silver Medal" ;
               cnt++; 
            }
            else if(cnt == 3){
               result[idx] = "Bronze Medal" ;
               cnt++; 
            }
            else{
               result[idx] = to_string(cnt);
               cnt++;
            }

        }
        return result;
    }
};