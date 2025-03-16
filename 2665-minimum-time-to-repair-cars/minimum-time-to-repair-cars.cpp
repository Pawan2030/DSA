class Solution {
public:
    
    bool is_Possible_To_Repair_Cars_In_Mid_Time(long long mid , vector<int>& ranks, int cars){

          long long num = 0;

          for(int i=0; i<ranks.size(); i++){
               
               long long count = sqrt(mid/(ranks[i]*1LL));
                num += count;
          }
          
          return num >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        
        int n = ranks.size();
        long long s = 1;
        int ele = *min_element(begin(ranks) , end(ranks));
        long long e = 1LL*ele*cars*cars;

        long long minTimeToRepairCars = e;

        while(s <= e){

            long long mid = s + (e-s)/2;

            if(is_Possible_To_Repair_Cars_In_Mid_Time(mid , ranks , cars)){
                minTimeToRepairCars = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return minTimeToRepairCars;
    }
};