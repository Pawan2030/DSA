class Solution {
public:

    
    bool isDigit(char ch){
        
        for(int i=0; i<=9; i++){
            
            if((ch-'0') == i){
                return true;
            }
        }

        return false;
    }

    int findTheNum(stack<char> &st){
        
        string val = "";

        while(!st.empty() && isDigit(st.top())){
            val += st.top();
            st.pop();
        }

        reverse(begin(val) , end(val));

        int num = stoi(val);
        return num;
    }

    string makeString(string &temp , int num){

        string out = "";

        for(int i=0; i<num; i++){
            out += temp;
        }

        for(char ch : out){
            cout<<ch;
        }cout<<endl;

        return out;

    }


    string decodeString(string s) {
        
        stack<char> st;
        int n = s.size();

        for(int i=0; i<n; i++){

            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{  // s[i] = ']'

                string temp = "";

                while(st.top() != '['){
                    temp += st.top();
                    st.pop();
                }

                st.pop(); // [
                int num = findTheNum(st);
                cout<<num<<endl;
              
                reverse(begin(temp) , end(temp));

                string Repeat = makeString(temp , num);

                //put again in stack

                for(char ss : Repeat){
                    st.push(ss);
                }

            }

        }

        //see the final things in stack
       
        string temp = "";

        while(!st.empty()){
            temp += st.top();
            st.pop();      
        }
         
        reverse(begin(temp) , end(temp));
        return temp;
    }
};