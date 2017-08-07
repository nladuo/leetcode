class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        long long data = x;
        bool isNegative = false;
        if (data < 0){
            isNegative = true;
            data = 0 - data;
        }
        vector<int> tmp;
        while (data != 0){
            tmp.push_back(data % 10);
            data /= 10;
        }
        for(int i = 0; i < tmp.size(); i++){
            result += tmp[i] * pow(10, tmp.size() - 1 - i);
        }
        if (isNegative){
            if (result > 2147483648){
                result = 0;
            }
            return 0 - result;
        }
        if (result > 2147483647){
            result = 0;
        }
        return result;
    }
};