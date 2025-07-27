class Solution {
public:
    int countHillValley(vector<int>& nums) {
         
         int hillCount   = 0;
         int valleyCount = 0;

         int i = 1;
         int n = nums.size();

         while(i < n-1){

            if(nums[i-1] < nums[i] && nums[i+1] < nums[i]){
                hillCount++;
                cout<<"HIll"<<endl;
            }
            else if(nums[i-1] > nums[i] && nums[i+1] > nums[i]){
                valleyCount++;
                cout<<"VALLY"<<endl;
            }
            else if(nums[i] == nums[i+1]){
                
                int prev = nums[i-1];

                while(i < n-1 && nums[i] == nums[i+1]){
                    i++;
                }

                if(i < n-1 && prev < nums[i] && nums[i+1] < nums[i]){
                    hillCount++;
                    cout<<"H"<<endl;
                }
                else if(i < n-1 && prev > nums[i] && nums[i+1] > nums[i]){
                    valleyCount++;
                    cout<<"V"<<endl;
                }

                // cout<<"PREV-"<<prev<<endl;
                // cout<<"CURR-"<<nums[i]<<endl;
                // cout<<"NEXT-"<<nums[i+1]<<endl;

            }
           
            i++;
            
         }

         return hillCount + valleyCount;
    }
};