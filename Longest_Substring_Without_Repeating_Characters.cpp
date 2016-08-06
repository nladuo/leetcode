#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char , int >pos_map;//存放上一个字符出现的位置 
        int max_len = 0;
        int last_repeated_pos = -1;
        for(int i = 0; i < s.length(); i++){
            char ch = s.at(i);
            //存在ch
            if (pos_map.find(ch) != pos_map.end()){
                if (last_repeated_pos < pos_map[ch]){
                    last_repeated_pos = pos_map[ch];
                }
            }
            int len = i - last_repeated_pos;
            if (len > max_len){
                max_len = len;
            }
            pos_map[ch] = i;
        }
        return max_len;
    }
};

int main()
{
    string s("abba");
    Solution solution;
    cout<<solution.lengthOfLongestSubstring(s)<<endl;
}