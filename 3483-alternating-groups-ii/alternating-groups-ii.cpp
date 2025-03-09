class Solution {
public:

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }

        int n = colors.size();
        int i = 0;
        int j = 1;

        int res = 0;

        while(j < n){

            if(colors[j-1] == colors[j]){
                i = j;
                j++;
                continue;
            }


            if(j-i+1 == k){
                res++;
                i++;
            }

             j++;

        }

        return res;
    }
};