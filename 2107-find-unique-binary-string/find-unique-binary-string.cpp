class Solution {
public:
    
    void solve(int p, string temp , string &res ,  unordered_set<string> &st){

        if(p==0){
            if(st.find(temp) == st.end()){
                res = temp;
                return;
            }
            return;
        }

        for(char ch = '0'; ch <='1'; ch++){
            temp += ch;
            if(res != "") break;
            solve(p-1,temp, res, st);
            temp.pop_back();
        }

    }

    string findDifferentBinaryString(vector<string>& nums) {
        
        int p = nums.size();
        unordered_set<string> st;

        for(string &num : nums){
            st.insert(num);
        }

        string res = "";

        solve(p , "" , res , st);
        return res;
    }
};