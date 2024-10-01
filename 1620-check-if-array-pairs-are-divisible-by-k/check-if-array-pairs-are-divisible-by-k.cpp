class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        map<int,int>mp;
        for(auto val:arr)
        {
            int rem = ((val%k)+k)%k;
            mp[rem]++;
        }
        for(auto [rem, cnt]:mp)
        {
            if(rem == 0) 
            {
                if(cnt%2) return false;
            }
            else if(rem * 2 == k)
            {
                if(cnt%2) return false;
            }
            else 
            {
                if(mp[rem] != mp[k-rem]) return false;
            }
        }
        return true;
    }
};