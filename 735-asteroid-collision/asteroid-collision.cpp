class Solution {
public:

    vector<int> asteroidCollision(vector<int>& ast) {

        stack<int> st;
        int n = ast.size();

        for(int i = 0; i<n; i++){

            if(ast[i] > 0){
                st.push(i);
            }
            else{

                while(!st.empty() && ast[st.top()] > 0){

                    if(ast[st.top()] > abs(ast[i])){
                        ast[i] = 0;
                        break;
                    }
                    else if(ast[st.top()] < abs(ast[i])){
                        ast[st.top()]  = 0;
                        st.pop();
                    }
                    else{
                         ast[st.top()]  = 0; 
                         ast[i] = 0;
                         st.pop();
                         break;
                    }
                }
            }

        }

        vector<int> ans;

        for(int num : ast){
            if(num != 0){
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};