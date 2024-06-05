class comp {
    public:

    bool operator () ( pair<char , int>  a , pair<char , int>  b){
           
           if(a.first == b.first){
              return a.second < b.second;
           }
            return a.first > b.first;
        }
};



class Solution {
public:
    
    typedef pair<char , int> p;


    string clearStars(string s) {
  
        priority_queue<p , vector<p>, comp> pq;

        for(int i=0; i<s.size(); i++){
             
             if(pq.empty()){
                pq.push({s[i] , i});
             }
             else if(s[i] == '*'){
                 
                 auto front = pq.top();
                 pq.pop();

                 int idx = front.second;
                 s[idx] = '$';
             }
             else{
                pq.push({s[i] , i});
             }
        }

        string temp = "";

        for(auto ch : s){

            if(ch != '$' and ch != '*'){
                temp += ch;
            }
        }

        return temp;
    }
};