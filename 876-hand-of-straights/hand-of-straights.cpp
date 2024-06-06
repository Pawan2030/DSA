class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        if(n % groupSize != 0){
            return false;
        }

        sort(begin(hand) , end(hand));

        unordered_map<int , int> mp;

        for(int num : hand){
            mp[num]++;
        }

        for(int card : hand){

            if(mp[card] > 0){
                 
                 for(int i=0; i<groupSize; i++){
                     
                     if(mp[card + i] == 0){
                        return false;
                     }

                     mp[card+i]--;
                 }
            }
        }

        // int i = 0;
        // while(i <= n - groupSize){
             
        //      int num = hand[i];

        //      if(mp[num] <= 0){
        //          i++; 
        //          continue;
        //      }

        //      int g = 0;

        //      while(g < groupSize){
                 
        //         if(mp.find(num) == mp.end()){
        //             return false;
        //          }
        //          mp[num]--;
        //          num += 1;
        //          g++;
        //      }

        //      i++;
        // }

        return true;
    }
};