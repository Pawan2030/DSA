class Solution {
public:

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        unordered_map<string , int> mp;

        for(string &st : cpdomains){

            int spaceIdx = st.find(' ');
            int count = stoi(st.substr(0 , spaceIdx));
            
            //rest string
            string Domain = st.substr(spaceIdx+1);

            while(!Domain.empty()){
                mp[Domain] += count;

                int dotIdx = Domain.find('.');

                if(dotIdx == string :: npos){
                    break;
                }
            
                Domain = Domain.substr(dotIdx+1);
            }
        }

        vector<string> res;

        for(auto it : mp){
            res.push_back(to_string(it.second) + " " + it.first);
        }

        return res;
    }
};