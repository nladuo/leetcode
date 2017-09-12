#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<char> tmp_str;
    vector<string> result;
    int len;
public:

    void generate(int pos, string digits, vector<string> reflect) {
        if (pos == len) {
            string str = "";
            for (int i = 0; i < len; i++) {
                str += tmp_str[i];
            }
            result.push_back(str);
        } else {
            string reflect_str = reflect[digits[pos] - '2'];
            for (int i = 0; i < reflect_str.length(); i++) {
                tmp_str[pos] = reflect_str[i];
                generate(pos + 1, digits, reflect);
            }
        }
    }


    vector<string> letterCombinations(string digits) {
        len = digits.length();
        if (len == 0) {
            return result;
        }
        result = vector<string>();
        tmp_str = vector<char>(digits.length());
        vector<string> reflect;
        reflect.push_back("abc");  // 2
        reflect.push_back("def");  // 3
        reflect.push_back("ghi");  // 4
        reflect.push_back("jkl");  // 5
        reflect.push_back("mno");  // 6
        reflect.push_back("pqrs"); // 7
        reflect.push_back("tuv");  // 8
        reflect.push_back("wxyz"); // 9

        generate(0, digits, reflect); // 递归生成
        return result;
    }
};


int main() {
    Solution s;
    vector<string> result = s.letterCombinations("23");
    for (int i = 0; i < result.size(); i++) {
        cout<< result[i] << endl;
    }
    return 0;
}
