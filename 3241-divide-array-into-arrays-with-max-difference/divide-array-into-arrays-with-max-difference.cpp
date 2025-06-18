class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(begin(nums),end(nums));

        vector<vector<int>> ans;

        for(int i=1; i<n-1; i+=3)
        {   
            vector<int> temp;
            if(nums[i] - nums[i-1] <=k && nums[i+1] - nums[i] <=k && nums[i+1] - nums[i-1] <=k )
            {
               temp.push_back(nums[i-1]);
               temp.push_back(nums[i]);
               temp.push_back(nums[i+1]);
                
                for(int i=0;i<temp.size();i++)
                {
                    cout<<temp[i] << " ";
                }
                cout<<endl;
               ans.push_back(temp);
            }
            else
            {  
               return {};
            }
        }
        return ans;
    }
};