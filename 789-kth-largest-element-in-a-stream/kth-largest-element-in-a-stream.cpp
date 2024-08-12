class KthLargest {
public:
     int cnt;
     priority_queue<int , vector<int> , greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {

       cnt = k;

       for(auto num : nums){
          add(num);
       }

    }
    
    int add(int val) {

        if(pq.size() < cnt){
            pq.push(val);
        }
        else if(val > pq.top()){
           pq.pop();
           pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */