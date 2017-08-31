#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int maxArea = 0;
      int i = 0, j = height.size() - 1;
      while (i < j) {
        int minHeight = (height[i] < height[j]) ? height[i] : height[j];
        int area = (j-i) * minHeight;
        if (area > maxArea) {
          maxArea = area;
        }
        if (height[i] < height[j]) {
          i++;
        } else {
          j--;
        }
      }
      return maxArea;
    }
};


int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    Solution solution;
    std::cout << "maxArea:" << solution.maxArea(vec) << '\n';
}
