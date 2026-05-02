class Solution {
public:
    
    bool isPossible(int val){
        
        bool rot = false;

        while(val >= 1){

            int temp = val%10;
            val = val/10;

            if(temp==3 || temp==4 || temp==7) return false;
            
            if(temp==2 || temp==5 || temp==6 || temp==9){
                rot = true;
            }
        }
        return rot;
    }

    int rotatedDigits(int n) {
        
        int cnt = 0;

        for(int i=1; i<=n; i++){

            if(isPossible(i)){
               // cout<<"i--"<<i<<endl;
                cnt++;
            }
        }

        return cnt;
    }
};