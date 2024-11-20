class Solution {
public:
    
    int n;
    
    void findNSE(vector<int>& arr , vector<int> &NSE){

        stack<int> st;

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && arr[st.top()] >= arr[i]){
               st.pop();
            }

            if(st.empty()){
                NSE[i] = n;
            }
            else{
                NSE[i] = st.top();
            }

            st.push(i);
        }
    }

    void findPSE(vector<int>& arr , vector<int> &PSE){

        stack<int> st;

        for(int i=0; i<n; i++){

            while(!st.empty() && arr[st.top()] >= arr[i]){
               st.pop();
            }

            if(st.empty()){
                PSE[i] = -1;
            }
            else{
               PSE[i] = st.top();
            }
            st.push(i);
        }
    }



    int largestRectangleArea(vector<int>& heights) {
        
        n = heights.size();
        vector<int> NSE(n); // this store idx of next smaller elment

        findNSE(heights , NSE);

        vector<int> PSE(n);
        findPSE(heights , PSE);

        int res = 0;

        for(int i=0; i<n; i++){
           
           int height = heights[i];

           int weight = (NSE[i] - PSE[i] -1);

           int Area   = height * weight;

           res        = max(res , Area);
        }

        return res;
    }
};