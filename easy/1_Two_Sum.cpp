#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#include "util.h"
using namespace std;

class Pair {
public:
    int t;
    int i;
    Pair(int _t, int _i) : t(_t), i(_i) {}
};

bool compare(Pair& n1, Pair& n2) {
    return n2.t > n1.t;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<Pair> vecs;
        vecs.reserve(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            vecs.push_back(Pair(nums[i], static_cast<int>(i)));
        }

        std::sort(vecs.begin(), vecs.end(), compare);

        vector<int> ret;

        int p = 0;
        int q = vecs.size() - 1;

        while (p < q) {
            int sum = vecs[p].t + vecs[q].t;
            if (sum == target) {
                ret.push_back(vecs[p].i);
                ret.push_back(vecs[q].i);
                break;
            } else if (sum < target) {
                ++p;
            } else {
                --q;
            }
        }
        /*
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if ((vecs[i].t + vecs[j].t) < target) {
                    // pass
                } else if ((vecs[i].t + vecs[j].t) > target) {
                    break;
                } else {
                    ret.push_back(vecs[i].i);
                    ret.push_back(vecs[j].i);
                    break;
                }
            }
        }
        */
        return ret;
    }
};

int main() {
    // int n[] = {2, 11, 7, 15};
    // int target = 9;
    int n[] = {3, 2, 3};
    int target = 6;
    vector<int> nums(n, n + sizeof(n) / sizeof(int));
    cout << vec2str(nums) << endl;

    vector<int> ret = Solution().twoSum(nums, target);

    cout << vec2str(ret) << endl;

    return 0;
}
