class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        long long l = 1;
        long long r = x + 1ll;

        while (r - l > 1) {
            long long mid = (l + r) / 2;
            if (1ll * mid * mid > x) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return l;

    }
};