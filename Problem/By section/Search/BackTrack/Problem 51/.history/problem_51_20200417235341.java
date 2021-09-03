import java.util.*;

class Solution{
    private boolean[][] is_attacked;
    private int[] choices;
    private final int[][] direction = {{-1,-1}, {-1,1}, {1,-1}, {1,1}};

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        if(n <= 0) return ans;

        is_attacked = new boolean[n][n];
        choices = new int[n];
        for(int i = 0; i < n; i ++){
            choices[i] = i;
        }

        backtrack(n, 0, ans, new ArrayList<Integer>());

        return ans;
    }

    public void backtrack(int n, int row, List<List<String>> ans, ArrayList<Integer> current){
        if(row == n - 1){
            ans.add(answer(n, current));
        }

        for(int choice : choices){
            if(is_attacked[row][choice]){
                continue;
            }


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

    public void attack(int i, int j){

        // block the whole column
        for(int k = 0; k < is_attacked[0].length; k ++){
            is_attacked[k][j] = true;
        }

        for(){

        }

    }


}