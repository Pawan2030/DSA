class Solution {
public:
    typedef long long ll;

    long long wonderfulSubstrings(string word) {

        unordered_map<ll , ll> mp;
        mp[0] = 1;

        int sum_xor = 0;

        ll ans = 0;

        for(char &ch : word){

            int shift = ch-'a';
            sum_xor ^= (1 << shift);
            ans += mp[sum_xor];

            for(char chr = 'a' ; chr <= 'j' ; chr++){

                shift = chr-'a';

                ll check = sum_xor^(1 << shift);

                ans += mp[check];
            }

            mp[sum_xor]++;
        }

        return ans;
    }
};