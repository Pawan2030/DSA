class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
          priority_queue<pair<double, pair<int, int>>, 
                       vector<pair<double, pair<int, int>>>, 
                       greater<pair<double, pair<int, int>>>>
                       pq;          
        
        int n = arr.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double frac = static_cast<double>(arr[i]) / arr[j]; // Perform floating-point division
                pq.push({frac , {arr[i] , arr[j]}});
            }
        }

        while(k > 1 && !pq.empty()){
            pq.pop();
            k--;
        }

        if(!pq.empty()){
            auto top = pq.top();
            vector<int> ans = {top.second.first, top.second.second};
            return ans;
        }
        
        return {}; 
    }
};