class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> q;

        for(int i=1; i<=n; i++){
            q.push(i);
        }

        while(q.size() > 1){

            int r = k;

            while(q.size() > 1 && r > 1){
               int ele = q.front();
               q.pop();
               q.push(ele);
               r--;
            }

            q.pop();
        }

        int top = q.front();
        return top;
    }
};