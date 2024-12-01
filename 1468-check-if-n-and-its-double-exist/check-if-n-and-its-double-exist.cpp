class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

       unordered_map<double,double> mp;

       for(int &num : arr){

           if(!mp.empty()){

               double val1 = (double)num*2.0;
               double val2 = (double)num/2.0;

               if(mp.find(val1) != mp.end() || mp.find(val2) != mp.end()) return true;
           }
           mp[num]++;
       } 
       
       return false;
    }
};