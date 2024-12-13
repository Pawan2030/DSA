class Solution {
public: 
    
    #define P pair<long long , long long>

    long long findScore(vector<int>& nums) {

        priority_queue<P , vector<P> , greater<P>> pq; // min heap
        vector<bool> vist(nums.size() , false);

        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i] , i});
        }

        long long score = 0;

        while(!pq.empty()){

            long long val = pq.top().first;
            long long idx = pq.top().second;
            pq.pop();

            if(vist[idx]) continue;

            int left = idx-1;
            int right = idx+1;

            if(left >= 0){
                nums[left] = 0;
                vist[left] = true;
            }

            if(right < nums.size()){
                nums[right] = 0;
                vist[right] = true;
            }
            
            cout<<nums[idx] << "-" << idx <<endl;
            score += nums[idx];
        }

        return score;
    }
};