class Solution {
public:

   struct comp{

    bool operator() (pair<char,int> &p1 , pair<char,int> &p2){

        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }

   };

    string clearStars(string s) {
        
        int n = s.size();
        priority_queue<pair<char,int> , vector<pair<char,int>>, comp> pq; //min heap with custom function

        for(int i=0; i<n; i++){
             
             if(s[i] == '*'){
                 auto it = pq.top();
                 pq.pop();

                 int idx = it.second;
                 s[idx] = '*';
             }
             else{
                pq.push({s[i] , i});
             }
        }

        string st = "";

        for(char ch : s){
            if(ch != '*'){
                st += ch;
            }
        }

        return st;
    }
};