class Solution {
public:
    string trim(string str){
        int start = 0, end = str.length() - 1;
        while(str[start] == ' '){
            start++;
        }
        while(str[end] == ' '){
            end--;
        }
        return str.substr(start, end - start + 1);
    }
    string ltrim0(string str, int start){
        while(str[start] == '0'){
            start++;
        }
        return str.substr(start, str.length() - start + 1);
    }

    string cutSpecialChar(string str, int start){
        for (int i = start; i < str.length(); ++i) {
            int num = str[i] - '0';
            if (num < 0 || num > 9){
                return str.substr(0, i);
            }
        }
        return str;
    }

    int myAtoi(string str) {
        str = trim(str);
        if (str.size() == 0) return 0;
        long long result = 0;
        bool hasPosOrNeg = (str[0] == '+' || str[0] == '-') ? true : false;
        bool isPositive = (str[0] == '+') ? true : false;

        if (hasPosOrNeg) {//有符号
            str = ltrim0(str, 1);
        } else{//无符号
            isPositive = true;
            str = ltrim0(str, 0);
        }
        str = cutSpecialChar(str, 0);
        if (str.length() > 10){
            if (!isPositive){
                return -2147483648;
            } else{
                return 2147483647;
            }
        }

        for (int i = 0; i < str.length(); ++i) {
            long long num = str[i] - '0';
            if (num < 0 || num > 9){
                return 0;
            }
            result += num * pow(10, str.length() - i - 1);
        }

        if (!isPositive){
            if (result > 2147483648){
                result = 2147483648;
            }
            return 0 - result;
        }
        if (result > 2147483647){
            result = 2147483647;
        }
        return result;
    }
};