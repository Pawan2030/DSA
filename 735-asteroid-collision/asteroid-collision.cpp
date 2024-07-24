class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        

         stack<int> st;
         vector<int> healths = asteroids;
         int n = asteroids.size();

        for(int idx = 0; idx<n; idx++){
             
            int val = asteroids[idx];

            if(val > 0){
                st.push(idx);
            }
            else{
               while(!st.empty() && asteroids[st.top()] > 0){
                
                int top = st.top();
                st.pop();
                
                if(healths[top] > abs(healths[idx])){
                    healths[idx] = 0;
                    st.push(top);
                    break;
                }
                else if(healths[top] < abs(healths[idx])){
                    healths[top] = 0;
                }
                else{
                    healths[top] = 0;
                    healths[idx] = 0;
                    break;
                }
            }
          }  
        }

        vector<int> arr;

        // while(!st.empty()){

        //     int val = healths[st.top()];
        //     st.pop();
        //     arr.push_back(val);
        // }

        // reverse(arr.begin() , arr.end());

        for(int i = 0 ; i<healths.size() ; i++){

            if(healths[i] != 0){
                arr.push_back(healths[i]);
            }
        }

        return arr;
    }
};