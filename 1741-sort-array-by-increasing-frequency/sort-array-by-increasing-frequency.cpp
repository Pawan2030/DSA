class CustomCompataror{

    public:

    bool operator()(pair<int , int> a , pair<int , int> b){

        int freq_a = a.second;
        int freq_b = b.second;

        if(freq_a > freq_b){
            return false;
        }
        else if(freq_a == freq_b){
            return a.first>b.first;
        }
        else{
            return true;
        }

    }

};

class Solution {
public:
    
    typedef pair<int , int> p;

    vector<int> frequencySort(vector<int>& nums) {

       //custom operator

       unordered_map<int , int> mp;

       for(int num : nums){
          mp[num]++;
       }

       priority_queue<pair<int , int> , vector<pair<int , int>> , CustomCompataror> pq;

       for(auto it : mp){
           int num  = it.first;
           int freq = it.second;

           pq.push({num , freq});
       }

       vector<int> arr;

       while(!pq.empty()){
           
           auto it = pq.top();
           int val  = it.first;
           int freq = it.second;
           pq.pop();

           while(freq--){
             arr.push_back(val);
           }
       }

       reverse(arr.begin() , arr.end());
  
       return arr;
    }
};