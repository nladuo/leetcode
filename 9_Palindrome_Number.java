//the c++ code cannot AC, used java code instead.
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x < 0) return false;
//         int tmp[10], index = 0;
//         while (x != 0){
//             tmp[index++] = x % 10;
//             x /= 10;
//         }
//         int start = 0, end = index - 1;
//         while (start < end){
//             if (tmp[start] != tmp[end]){
//                 return false;
//             }
//             start++;end--;
//         }
//         return true;
//     }
// };
public class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        int[] tmp = new int[10];
        int index = 0;
        while (x != 0){
            tmp[index++] = x % 10;
            x /= 10;
        }
        int start = 0, end = index - 1;
        while (start < end){
            if (tmp[start] != tmp[end]){
                return false;
            }
            start++;end--;
        }
        return true;
    }
}

