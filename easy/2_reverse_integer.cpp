#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>

#include "util.h"
using namespace std;

class Solution {
public:
    int reverse(int x) {

        long num = x;
        int flag = 1;
        if (flag > 0) {
            num = -num;
            flag = -1;
        }

        int nums[11];
        memset(nums, 0, 11 * sizeof(int));
        int idx = 0;
        while (num > 0) {
            int n = num % 10;
            num = num / 10;
            nums[idx++] = n;
        }

        long ret = 0;
        for (int i = 0; i < idx; ++i) {
            ret = ret * 10;
            ret += nums[i];
        }
        
        if (flag == 0) {
            if (ret > 0x7FFFFFFF) {
                ret = 0;
            }
        } else {
            if (ret > 0x80000000) {
                ret = 0;
            }
            ret = -ret;
        }
        return (int)ret;
    }
};

int main() {

    printf("%ld\n", (long)(pow(2, 31) - 1));
    cout << "int:"  << sizeof(int) << endl;
    cout << "long:" << sizeof(long) << endl;
    printf("%d\n", 0x7FFFFFFF);
    printf("%d\n", 0x7FFFFFFF + 1);
    printf("%d\n", 0x80000000);
    printf("%d\n", 0x80000000 + 1);

    cout << "------------------------------" << endl;

    // int i = 120;
    // int i = -123;
    // int i = 1534236469;
    int i = -2147483648;

    cout << i << endl;
    auto ret = Solution().reverse(i);

    cout << ret << endl;

    return 0;
}
