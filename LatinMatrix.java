// 一个4阶Latin方是一个4X4的方格，在它的每个方格内填入1,2,3或4，并使得每个数字在每行、每列都恰好出现一次。
// 用回溯法求出所有第一行为1,2,3,4的所有4阶Latin方。
package homework;


import java.util.ArrayList;

public class LatinMatrix {

    private int[][] temp = new int[][]{{-1,-1,-1, -1}, {-1,-1,-1, -1}, {-1,-1,-1, -1}, {-1,-1,-1, -1}};
    public ArrayList<String> results = new ArrayList<>();

    public int[] getNumbers(int row, int col) { // 获取当前位置可选的值
        int[] numbers = new int[]{1, 2, 3, 4};

        for (int i = 0; i < col; i++) { // 检查行
            numbers[temp[row][i] - 1] = -1;
        }

        for (int i = 0; i < row; i++) { // 检查列
            numbers[temp[i][col] - 1] = -1;
        }

        return numbers;
    }

    public void recurse(int location) { // 深度优先遍历
        if (location == 16) { // 遍历结束, 打印结果
            String result = "<";
            for (int i = 1; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (j == 3 && i == 3) {
                        result += temp[i][j];
                    } else {
                        result += temp[i][j] + ",";
                    }
                }
            }
            result += ">";
            results.add(result);
            return;
        }

        int row = location / 4;
        int col = location % 4;

        for (int number : getNumbers(row, col)) {
            if (number != -1) {
                temp[row][col] = number;
                recurse(location + 1);
            }
        }
    }


    public static void main(String[] args) {
        LatinMatrix matrix = new LatinMatrix();
        matrix.recurse(0);
        for (String result : matrix.results) {
            System.out.println(result);
        }
        System.out.println("len(matrix.results) = " + matrix.results.size());
    }

}


