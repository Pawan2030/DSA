class Solution {
public:


    string replaceWords(vector<string>& dictionary, string send) {
         
        unordered_map<string , int> mp;

        for(string s : dictionary){
            mp[s]++;
        }

        int i = 0, j = 0;
        int n = send.length();

        while(i < n){

            while(j < n && send[j] != ' '){
                
                string temp = send.substr(i , j-i+1);
                j++;

                if(mp.find(temp) != mp.end()){

                    while(j < n && send[j] != ' '){
                        send[j] = '$';
                        j++;
                    }
                } 
            }
            i = j+1;
            j = i;
        }

        string ans = "";
        i = 0;

        while(i < n){
             
            //  if(send[i] == ' '){
            //     cout<<" ";
            //  }
            //  else{
            //     cout<<send[i];
            //  }
            if(send[i] != '$'){
               ans += send[i];
            }
            i++;
        }

        return ans;
    }
};