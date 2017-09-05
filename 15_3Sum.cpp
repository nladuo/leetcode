#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> >  results;
    if (nums.size() <= 2) {
      return results;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      if (i>0 && nums[i-1] == nums[i]) continue;
      int a = nums[i];
      int p = i+1;
      int q = nums.size() - 1;
      while (p < q) {
        int b = nums[p];
        int c = nums[q];
        if (a+b+c == 0) {
          vector<int> v;
          v.push_back(a);
          v.push_back(b);
          v.push_back(c);
          results.push_back(v);
          while(p<nums.size()-1 && nums[p]==nums[p+1]) p++;
          while(q>0 && nums[q]==nums[q-1]) q--;
          p++;
          q--;
        } else if (a+b+c < 0) {
          while(p<nums.size()-1 && nums[p]==nums[p+1]) p++;
          p++;
        } else {
          while(q>0 && nums[q]==nums[q-1]) q--;
          q--;
        }
      }
    }
    return results;
  }
};


int main()
{
    std::vector<int> vec;
    // vec.push_back(0);
    // vec.push_back(0);
    // vec.push_back(0);
    // vec.push_back(0);

    vec.push_back(-4);
    vec.push_back(-2);
    vec.push_back(-2);
    vec.push_back(-2);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(6);
    Solution solution;
    vector<vector<int> > results = solution.threeSum(vec);
    for (size_t i = 0; i < results.size(); i++) {
      std::cout << results[i][0] << " " << results[i][1] << " " << results[i][2] << '\n';
    }
}
