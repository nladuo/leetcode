#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) {
      return "";
    }
    if (strs.size() == 1) {
      return strs[0];
    }
    string common_prefix = "";
    for (int i = 0; i < strs[0].length(); i++) {
      char ch = strs[0].at(i);
      for (int j = 1; j < strs.size(); j++) {
        // std::cout << "i:"<<i<<"j:" << j <<'\n';
        // 越界问题
        if (i == strs[j].length()) {
          return common_prefix;
        }
        // 有一个不同就返回
        if (strs[j].at(i) != ch){
          return common_prefix;
        }
      }
      common_prefix += ch;
    }

    return common_prefix;
  }
};


int main()
{
    std::vector<string> vec;
    // vec.push_back("1113");
    // vec.push_back("112");
    // vec.push_back("113");
    // vec.push_back("114");
    Solution solution;
    std::cout << "longestCommonPrefix:" << solution.longestCommonPrefix(vec) << '\n';
}
