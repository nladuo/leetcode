// 2.试写出 0/1 背包问题的队列式分枝限界算法程序，并找一个物品个数是 16 的例子检验程序的运行情况。
package homework;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;


class Node{
    public Node parent;
    public int level; //层级
    public int cc;    // 剩余容量
    public int xi;    // 第level层装不装
    public int val;   // 当前的价值
    public int upper_bound;  //当前上界
    public int base_bound;   //当前下界


    Node(Node parent, int level, int cc, int xi, int val){
        this.parent = parent;
        this.level = level;
        this.cc = cc;
        this.xi = xi;
        this.val = val;
    }
}

public class Bag01 {

    int getUpperBound(int[] P, int[] W, int N, Node node) { //使用贪心法估计上界
        int val = node.val;
        int cap = node.cc;
        for (int i = node.level; i < N; i++) {
            if (cap - W[i] >= 0) {
                val += P[i];
                cap -= W[i];
            } else {
                val += (float)(cap) / W[i] * P[i];
                break;
            }
        }
        return val;
    }

    int getBaseBound(int[] P, int[] W, int N, Node node) {  // 随便装满,作为下界
        int val = node.val;
        int cap = node.cc;
        for (int i = node.level; i < N; i++) {
            if (cap - W[i] >= 0) {
                val += P[i];
                cap -= W[i];
            }
        }
        return val;
    }


    void LCKNAP(int[] P, int[] W, int M, int N) {
        ArrayList<Node> results = new ArrayList<>(); // 记录最后一层的结果
        Node tree_node = new Node(null, 0, M, -1, 0); // 第一层
        tree_node.base_bound = getBaseBound(P, W, N, tree_node);  // 第一层的上界
        tree_node.upper_bound = getUpperBound(P, W, N, tree_node); // 第一层的下界
        int max_val = tree_node.base_bound;  // 记录当前的最大下界, 如果有节点的上界比这个值低的话, 就舍弃

        PriorityQueue<Node> queue = new PriorityQueue<>(10, new Comparator<Node>() { // 优先队列,根据节点的下界排序
            @Override
            public int compare(Node o1, Node o2) {
                if(o2.base_bound > o1.base_bound) return 1;
                else if(o2.base_bound < o1.base_bound) return -1;
                else return 0;
            }
        });
        queue.add(tree_node);

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            int level = node.level;
            if (level == N) {
                results.add(node);
                continue;
            }
            // 生成左儿子
            if (node.cc >= W[level]) {  // 可以装
                Node l_node = new Node(node, level + 1, node.cc - W[level], 1, node.val + P[level]);
                l_node.upper_bound = node.upper_bound; //和爹相同
                l_node.base_bound = node.base_bound;
                queue.add(l_node);
            }

            // 生成右儿子
            Node r_node = new Node(node, level + 1, node.cc, 0, node.val);
            r_node.upper_bound = getUpperBound(P, W, N, r_node); //和爹相同
            r_node.base_bound = getBaseBound(P, W, N, r_node);
            if (r_node.upper_bound < max_val) {
                continue;
            }
            queue.add(r_node);
            if (r_node.base_bound > max_val) {
                max_val = r_node.base_bound;
            }
        }
        // 输出结果
        for (Node result : results){
            System.out.println("track:" + backtrack(result)+ ", value:" + result.val);
        }
    }

    String backtrack(Node node) {  // 回溯节点
        String str = "";
        while (node.level != 0) {
            str += node.xi;
            node = node.parent;
        }
        StringBuilder sb = new StringBuilder(str);
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        //满足： P[i]/W[i]P[i+1]/W[i+1]
        int[] P = new int[]{10, 12, 16, 22, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35};
        int[] W = new int[]{2, 4, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
        int c = 60;
        Bag01 bag01 = new Bag01();
        bag01.LCKNAP(P, W, c, 16);


//        int[] P = new int[]{10, 10, 12, 18};
//        int[] W = new int[]{2, 4, 6, 9};
//        Bag01 bag01 = new Bag01();
//        bag01.LCKNAP(P, W, c, 4);
    }
}
