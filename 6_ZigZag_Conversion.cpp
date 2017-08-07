class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result;
        for (int i = 0; i < numRows; ++i) {
            int pos = i;
            bool isDown = true;
            while (pos < s.length()){
                int tmp = 0;
                if (isDown){
                    tmp = 2 * (numRows - i - 2) + 2;
                    if (tmp != 0) result += s[pos];
                    pos += tmp;
                    isDown = false;
                }else{
                    tmp = 2 * (numRows -(numRows-1-i) - 2) + 2;
                    if (tmp != 0) result += s[pos];
                    pos += tmp;
                    isDown = true;
                }
            }
        }
        return result;
    }
};