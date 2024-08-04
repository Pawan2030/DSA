class Solution {
public:

    int findTheWinner(int n, int k) {

        queue<int> q;

        for(int i=1; i<=n; i++){
            q.push(i);
        }

        int cnt = 1;

        while(q.size() > 1){

            int ele = q.front();
            q.pop();

            if(cnt == k){  
                cnt = 1;
            }
            else{
                q.push(ele);
                cnt++;
            }

        }
        return q.front();
    }
};