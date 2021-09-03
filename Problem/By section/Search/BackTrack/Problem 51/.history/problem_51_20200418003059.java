import java.util.*;

class Solution{
    private int[][] is_attacked;
    private int[] choices;
    private final int[][] directions = {{-1,-1}, {-1,1}, {1,-1}, {1,1}};

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        if(n <= 0) return ans;

        is_attacked = new int[n][n];
        choices = new int[n];
        for(int i = 0; i < n; i ++){
            choices[i] = i;
        }

        backtrack(n, 0, ans, new ArrayList<Integer>());

        return ans;
    }

    public void backtrack(int n, int row, List<List<String>> ans, ArrayList<Integer> current){
        if(row == n){
            System.out.println("Success!!!!!!");
            ans.add(answer(n, current));
            return;
        }

        for(int choice : choices){
            if(is_attacked[row][choice] > 0){
                continue;
            }

            is_attacked[row][choice] += 1;
            System.out.printf("Adding queen at i = %d j = %d\n", row, choice);
            attack(row, choice, n);
            print(is_attacked);
            current.add(choice);

            backtrack(n, row + 1, ans, current);

            is_attacked[row][choice] -= 1;
            clear_attack(row, choice, n);
            current.remove(current.size() - 1);
        }

    }

    public List<String> answer(int n, ArrayList<Integer> ans){
        List<String> answer = new ArrayList<>();
        for(int each_q : ans){
            StringBuilder builder = new StringBuilder();
            for(int i = 0; i < n; i++){
                if(i == each_q){
                    builder.append("Q");
                    continue;
                }
                builder.append(".");
            }
            answer.add(builder.toString());
        }

        return answer;
    }

    public void attack(int i, int j, int n){

        // block the whole column
        for(int k = 0; k < is_attacked.length; k ++){
            is_attacked[k][j] += 1;
        }

        // block the diagonal
        for(int[] direction : directions){
            int temp = 1;
            while(i + temp * direction[0] >= 0 && i + temp * direction[0] < n 
                && j + temp * direction[1] >= 0 && j + temp * direction[1] < n){
                    is_attacked[i + temp * direction[0]][j + temp * direction[1]] += 1;
                    temp ++;
            }
        }

    }

    public void clear_attack(int i, int j, int n){

        // free the column
        for(int k = 0; k < is_attacked[0].length; k ++){
            is_attacked[k][j] -= 1;
        }

        // free the diagonal
        for(int[] direction : directions){
            int temp = 1;
            while(i + temp * direction[0] >= 0 && i + temp * direction[0] < n 
                && j + temp * direction[1] >= 0 && j + temp * direction[1] < n){
                    is_attacked[i + temp * direction[0]][j + temp * direction[1]] -= 1;

                    temp ++;
            }
        }
    }

    public void print(int[][] ans){
        for(int[] arr : ans){
            for(int i : arr){
                System.out.print(((i > 0) ? "X" : "O") + " ");
            }
            System.out.println();
        }
    } 
}

public class problem_51{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.solveNQueens(4));
    }
}