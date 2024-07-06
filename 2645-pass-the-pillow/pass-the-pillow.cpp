class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle_length = 2 * (n - 1);
        time %= cycle_length;

        if (time < n) {
            return time + 1;
        } else {
            return 2 * n - time - 1;
        }
    }
};
