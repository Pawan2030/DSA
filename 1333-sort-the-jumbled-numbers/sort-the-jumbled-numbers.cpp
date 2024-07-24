// class Compatotar{

//     bool operator()(pair<int , pair<int , int>> a , pair<int , pair<int , int >> b){


//     }
// };


class Solution {
public:
    
    int makeValue(int num , vector<int>& mapping){

        if(num == 0){
            return mapping[num];
        }

        string st;

        while(num){

            int digit = num%10;
            num /= 10;

            int val = mapping[digit];
            st += to_string(val);
        }

        reverse(st.begin() , st.end());
        
        int data = stoi(st);

        return data;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<int> arr;

        for(int num : nums){
            
            int val = makeValue(num , mapping);
            cout<<"VAL->"<<val<<endl;
            arr.push_back(val);
        }

        priority_queue<pair<int,pair<int , int>> , vector<pair<int ,pair<int, int>>> , greater<pair<int , pair<int,int>>>> pq;

        for(int i = 0; i<nums.size() ; i++){
            pq.push({arr[i], {i , nums[i]}});
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second.second);
            pq.pop();
        }
        
        return ans;
    }
};