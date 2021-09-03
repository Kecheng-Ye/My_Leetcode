import java.util.*;
class solution{
    // Time: O(n * sqrt(n)) Space: O(n) 
    public int numSquares(int n) {
        // all square numbers less than n
        List<Integer> squares = generateSquares(n);
        Queue<Integer> queue = new LinkedList<>();
        // remember the number that has already been marked 
        boolean[] marked = new boolean[n + 1];
    
        queue.add(n);
        marked[n] = true;
        int level = 0;

        // BFS
        while (!queue.isEmpty()) {
            int size = queue.size();
            level++;
            while (size-- > 0) {
                int cur = queue.poll();
                for (int s : squares) {
                    // go to the number deducted by each squres
                    int next = cur - s;
                    if (next < 0) {
                        break;
                    }
                    if (next == 0) {
                        return level;
                    }
                    if (marked[next]) {
                        continue;
                    }

                    marked[next] = true;
                    queue.add(next);
                }
            }
        }
        return n;
    }
    
    /**
     * 生成小于 n 的平方数序列
     * @return 1,4,9,...
     */
    // Because the differece of two square is a linear function
    // so we can use add to replace square
    private List<Integer> generateSquares(int n) {
        List<Integer> squares = new ArrayList<>();
        int square = 1;
        int diff = 3;
        while (square <= n) {
            squares.add(square);
            square += diff;
            diff += 2;
        }
        return squares;
    }
}