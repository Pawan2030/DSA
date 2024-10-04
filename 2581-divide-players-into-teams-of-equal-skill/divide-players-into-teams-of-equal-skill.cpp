class Solution {
public:

    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size();
        sort(begin(skill) , end(skill));
        
        int mini = skill[0];
        int maxi = skill[n-1];

        int sum = maxi+mini;

        int i = 0;
        int j = n-1;
        long long res = 0;

        while(i < j){

            int val1 = skill[i];
            int val2 = skill[j];

            if(val1 + val2 != sum){
                return -1;
            }

            res += (val1*val2*1LL);

            i++;
            j--;
        }
        
        return res;
    }
};