class Solution {
public:

   vector<int> getNSR(vector<int>& height){
    
    int size = height.size();
    vector<int> arr(size);

    stack<int> st;

    for(int i= size -1; i >= 0; i--){

        if(st.empty()){
            arr[i] = size;
        }
        else{

            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }

            if(st.empty()){
                arr[i] = size;
            }
            else{
              arr[i] = st.top();
            }
        }
         st.push(i);
    }
    return arr;
   }

    vector<int> getNSL(vector<int>& height){
    
    int size = height.size();
    vector<int> arr(size);

    stack<int> st;

    for(int i= 0; i < size; i++){

        if(st.empty()){
            arr[i] = -1;
        }
        else{

            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }

            if(st.empty()){
                arr[i] = -1;
            }
            else{
              arr[i] = st.top();
            }
        }
       st.push(i);
    }
    return arr;
   }




   int findArea(vector<int>& height){

     int maxArea = INT_MIN;
     int size = height.size();

     vector<int> NSL = getNSL(height);
     vector<int> NSR = getNSR(height);

     for(int i=0; i<size; i++){

        int area = height[i] * (NSR[i] - NSL[i] - 1);
         maxArea = max(maxArea , area);   
     }
     return maxArea;
   }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size(); //row size
        int n = matrix[0].size(); //col size

        vector<int> height(n , 0);

        int maxArea = INT_MIN;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    height[j] += 1;
                }
            }

            maxArea = max(maxArea , findArea(height));
        }
        return maxArea;
    }
};