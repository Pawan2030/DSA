class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> st;
        int i = 0;

        while(i < n){

            if(nums[i] > 0){
                st.push(nums[i]);
                cout<<"1"<<endl;
            }
            else if(st.empty() || st.top() < 0){
                st.push(nums[i]);
                 cout<<"x"<<endl;
            }
            else{
                

                if(!st.empty() && abs(nums[i]) == st.top()){
                     st.pop();
                      cout<<"2"<<endl;
                }
                else{

                    while(!st.empty() && nums[i] < 0 && st.top() > 0 && st.top() < abs(nums[i])){
                      st.pop();
                      cout<<"3"<<endl;
                    }

                if(!st.empty() && abs(nums[i]) == st.top()){
                     st.pop();
                      cout<<"2"<<endl;
                }
                else if(st.empty() || st.top() < 0){
                        st.push(nums[i]);
                    }

                }
            }

            i++;
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(begin(ans) , end(ans));
        return ans;

    }
};