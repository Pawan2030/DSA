class Solution {
public:

    bool check(string st){

        if(st.size() == 1){
            //  cout<<st[0]<<endl; 
             return true;
        } 

        for(int i=1; i<st.size(); i++){
           
        //    cout<<st[i];
           if(st[i-1] != st[i]){
               return false;
           }
        }
        // cout<<endl;
        return true;
    }

    int maximumLength(string s) {

        int n = s.size();

        unordered_map<string , int> mp;

        int maxLen = -1;

        for(int i=0; i<n; i++){

            for(int j=i; j<n; j++){

            string sub = s.substr(i , j-i+1); 
            // ****PAWAN FORGOT***-->(start from here , length of substr)

           if(check(sub)){
                
                mp[sub]++;
                
                for(int i=0; i<sub.size(); i++){
                    cout<<sub[i];
                }
                cout<<"->"<< mp[sub]<<endl; 
            
                if( mp[sub] >= 3)
                  
                  maxLen = max(maxLen , static_cast<int>(sub.length()));
           } 
           else{
               break;
           } 

        }     
    }
       return maxLen;   
    }
};