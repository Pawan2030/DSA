class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        long long max_sum=arr[0],curr_sum=0;
        int n = arr.size();
    for(int i=0;i<n;i++){
        curr_sum +=arr[i];
        if(curr_sum>max_sum){
            max_sum=curr_sum;
        }
        if(curr_sum<0){
            curr_sum=0;
        }
    }
    return max_sum;
}

};