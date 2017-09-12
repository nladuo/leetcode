#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    long int get_distance(long int v1, long int v2) {
        if (v1 > v2) {
            return v1 - v2;
        } else {
            return v2 - v1;
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        long int result_distance = 2147483647;
        int result_sum = 2147483647;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i>0 && nums[i-1] == nums[i]) continue;
            int a = nums[i];
            int p = i+1;
            int q = nums.size() - 1;
            while (p < q) {
                int b = nums[p];
                int c = nums[q];
                long int distance = get_distance(a+b+c, target);
                if (distance == 0) {
                    return target;
                } else if (a+b+c < target) {
                    while(p<nums.size()-1 && nums[p]==nums[p+1]) p++;
                    p++;
                } else {
                    while(q>0 && nums[q]==nums[q-1]) q--;
                    q--;
                }
                if (distance < result_distance) {
                    result_distance = distance;
                    result_sum = a+b+c;
                }
            }
        }
        return result_sum;
    }
};


int main() {
    int target = 1;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);

    Solution s;
    cout<<s.threeSumClosest(nums, target)<<endl;
    return 0;
}
