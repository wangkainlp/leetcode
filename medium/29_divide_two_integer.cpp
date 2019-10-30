#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <climits>
using namespace std;

class Solution {
public:

    long positive_divide(long dividend, long divisor) {
        if (divisor == 1) { return dividend; }
        if (dividend == 0) { return 0L; }

        if (dividend == divisor) {
            return 1L;
        } else if (dividend < divisor) {
            return 0L;
        }

        int nums[11];
        memset(nums, 0, 11 * sizeof(int));
        int idx = 0;
        int num = dividend;
        while (num > 0) {
            int n = num % 10;
            num = num / 10;
            nums[idx++] = n;
        }

        int nums_[11];
        memset(nums_, 0, 11 * sizeof(int));
        idx = 0;
        num = dividend;
        while (num > 0) {
            int n = num % 10;
            num = num / 10;
            nums[idx++] = n;
        }



        long num = dividend;
        long sum = 0;
        long quotient = 0;
        for (long i = 1; i <= INT_MAX&& sum <= dividend; ++i) {
            sum += divisor;
            quotient++;
            // cout << "sum:" << sum << endl;
            if (sum >= dividend) {
                break;
            }
        }
        if (sum == dividend) {
            // pass
        } else {
            quotient--;
        }
        // cout << "quotient:" << quotient << endl;
        return quotient;
    }

    int divide(int dividend, int divisor) {
        if (dividend == 0) { return 0; }

        int flag = (dividend >> 31) & 0x01;
        if (dividend > 0) {
            if (divisor > 0) {
                flag = 1;
            } else {
                flag = -1;
            }
        } else {
            if (divisor > 0) {
                flag = -1;
            } else {
                flag = 1;
            }
        }

        long dividend_L = dividend;
        long divisor_L = divisor;
        dividend_L = abs(dividend_L);
        divisor_L = abs(divisor_L); 

        long quotient = positive_divide(dividend_L, divisor_L);
        // cout << "flag:" << flag << endl;
        // cout << "quotient:" << quotient << endl;

        quotient = flag * quotient;
        if (quotient > INT_MAX) {
            quotient = INT_MAX;
        }
        if (quotient < INT_MIN) {
            quotient = INT_MIN;
        }

        return quotient;
    }
};

int main() {

    int a = 10;
    int b = 3;
    cout << a << "/" << b << endl;
    cout << Solution().divide(a, b) << endl;;
    cout << Solution().divide(-2147483648, -1) << endl;;
    cout << Solution().divide(7, -3) << endl;;
    cout << Solution().divide(-2147483648, 2) << endl;;
    return 0;
}
