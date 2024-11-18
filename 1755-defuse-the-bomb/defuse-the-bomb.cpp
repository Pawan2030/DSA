class Solution {
public:
    
    int n;
    
    // k > 0

    vector<int> solve(vector<int> &temp , int k){
         
          vector<int> res;
         
          int sum = 0;
          int i = 1;

          while(i <= k){
             sum += temp[i];
             i++;
          }

          res.push_back(sum);

          while(i < 2*n){
             
             sum -= temp[i-k];
             sum += temp[i];

             if(res.size() < n)
              res.push_back(sum);

             i++;
          }

          return res;
    }
    
    // k < 0

    vector<int> answer(vector<int> &temp , int k){
         
        vector<int> res;
        int size = temp.size();

        int sum = 0;
        int i = n+k;

        while(i < n){
            sum += temp[i];
            i++;
        }

        res.push_back(sum);

        while(i < 2*n){
            
            sum -= temp[i+k];
            sum += temp[i];

            if(res.size() < n)
              res.push_back(sum);
              
            i++;
          }

          return res;
    }
    
    
    vector<int> decrypt(vector<int>& code, int k) {
        
        n = code.size();
      
        vector<int> temp(code.begin() , code.end());
       
        temp.insert(temp.end() , code.begin() , code.end());

        if(k==0){
            return vector<int> (n , 0);
        }
        else if(k > 0){
            return solve(temp , k);
        }

        //solve k < 0 
        return answer(temp , k);
    }
};