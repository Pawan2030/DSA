class Solution {
public:
    
    int n;

    void print(vector<int> &temp){

        for(int num : temp){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    bool canTake(vector<int>& temp , int k){
         
         //print(temp);

         int size = temp.size();

         if(size == 1){
            return true;
         }

         int i = 0;

         while(i < size -1){

            int j = i+1;

            while(j < size){

                if(abs(temp[i] - temp[j]) == k){
                return false;
            }
            j++;
        }
            i++;
         }

        //  for(int i = 0 ; i < temp.size()-1; i++){
             
        //      for(int j = i+1 ; j < temp.size(); j++){

        //         if(abs(temp[i] - temp[j]) == k){
        //         return false;
        //      }
        //     }
        //  }

         return true;
    }

    void solve(int i , vector<int>& nums , int k , vector<int>& temp , int &cnt){

        //base case
        if(i >= n){

            if(canTake(temp , k)){
                cnt++;
            }

            return;
        }


        temp.push_back(nums[i]);
        solve(i+1 , nums , k , temp , cnt);
        temp.pop_back();
        solve(i+1 , nums , k , temp , cnt);
     
        return;
    }



    int beautifulSubsets(vector<int>& nums, int k) {
        
         n = nums.size();
         sort(nums.begin() , nums.end());
         vector<int> temp;
         int cnt = 0;

         solve(0 , nums , k , temp , cnt);

         return cnt-1;
    }
};