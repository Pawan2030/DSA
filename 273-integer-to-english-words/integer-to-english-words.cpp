class Solution {
public:
    unordered_map<int, string> belowTen;
    unordered_map<int, string> belowTwenty;
    unordered_map<int, string> belowHundred;

    void initialize() {
        belowTen[1] = "One";
        belowTen[2] = "Two";
        belowTen[3] = "Three";
        belowTen[4] = "Four";
        belowTen[5] = "Five";
        belowTen[6] = "Six";
        belowTen[7] = "Seven";
        belowTen[8] = "Eight";
        belowTen[9] = "Nine";

        belowTwenty[10] = "Ten";
        belowTwenty[11] = "Eleven";
        belowTwenty[12] = "Twelve";
        belowTwenty[13] = "Thirteen";
        belowTwenty[14] = "Fourteen";
        belowTwenty[15] = "Fifteen";
        belowTwenty[16] = "Sixteen";
        belowTwenty[17] = "Seventeen";
        belowTwenty[18] = "Eighteen";
        belowTwenty[19] = "Nineteen";

        belowHundred[2] = "Twenty";
        belowHundred[3] = "Thirty";
        belowHundred[4] = "Forty";
        belowHundred[5] = "Fifty";
        belowHundred[6] = "Sixty";
        belowHundred[7] = "Seventy";
        belowHundred[8] = "Eighty";
        belowHundred[9] = "Ninety";
    }

    void solve(int num, string &ans) {
        if (num == 0) {
            return;
        }

        if (num < 10) {
            ans += belowTen[num];
        } else if (num < 20) {
            ans += belowTwenty[num];
        } else if (num < 100) {
            ans += belowHundred[num / 10];
            if (num % 10 != 0) {
                ans += " ";
                solve(num % 10, ans);
            }
        } else if (num < 1000) {
            ans += belowTen[num / 100] + " Hundred";
            if (num % 100 != 0) {
                ans += " ";
                solve(num % 100, ans);
            }
        } else if (num < 1000000) {
            solve(num / 1000, ans);
            ans += " Thousand";
            if (num % 1000 != 0) {
                ans += " ";
                solve(num % 1000, ans);
            }
        } else if (num < 1000000000) {
            solve(num / 1000000, ans);
            ans += " Million";
            if (num % 1000000 != 0) {
                ans += " ";
                solve(num % 1000000, ans);
            }
        } else {
            solve(num / 1000000000, ans);
            ans += " Billion";
            if (num % 1000000000 != 0) {
                ans += " ";
                solve(num % 1000000000, ans);
            }
        }
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        initialize();

        string ans = "";
        solve(num, ans);
        return ans;
    }
};
