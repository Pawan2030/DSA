class CustomStack {
public:

    int n;
    stack<int> st;

    CustomStack(int maxSize) {
      n = maxSize;
    }
    
    void push(int x) {
        
        if(st.size() < n){
            st.push(x);
        }
    }
    
    int pop() {
        
        if(!st.empty()){
            int top = st.top();
            st.pop();
            return top;
        }
        else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        
        //all increment
        stack<int> temp;

        if(st.size() < k){
            
            while(!st.empty()){

                int top = st.top();
                st.pop();
                temp.push(top+val);
            }

            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
        else{
            
            while(!st.empty()){
                int top = st.top();
                st.pop();
                temp.push(top);
            }

            int cnt = 1;

            while(!temp.empty() && cnt <= k){
                int top = temp.top();
                temp.pop();
                st.push(top+val);
                cnt++;
            }

             while(!temp.empty()){
                int top = temp.top();
                temp.pop();
                st.push(top);
            }
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */