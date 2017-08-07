class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return 0;
        bool table[1000][1000] = {false};
        string longestStr = s.substr(0, 1);
        for (int i = 0; i < s.length(); i++){
            table[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i+1]){
                longestStr = s.substr(i, 2);
                table[i][i+1] = true;
            }
        }
        for (int len = 3; len <= s.length(); len++){
            for (int i = 0; i < s.length()-len+1; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && table[i+1][j-1]){
                    longestStr = s.substr(i, len);
                    table[i][j] = true;
                }
            }
        }
        return longestStr;
    }
};