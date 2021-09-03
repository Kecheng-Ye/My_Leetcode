import java.util.*;

class Solution{
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> permutes = new ArrayList<>();
        List<Integer> permuteList = new ArrayList<>();
        Arrays.sort(nums);  // 排序
        boolean[] hasVisited = new boolean[nums.length];
        backtracking(permuteList, permutes, hasVisited, nums);
        return permutes;
    }
    
    private void backtracking(List<Integer> permuteList, List<List<Integer>> permutes, boolean[] visited, final int[] nums) {
        if (permuteList.size() == nums.length) {
            System.out.println("add " + permuteList);
            permutes.add(new ArrayList<>(permuteList));
            return;
        }
    
        for (int i = 0; i < visited.length; i++) {
            print(visited);
            if (i != 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                System.out.println("nums["+i + "] == nums[" + (i - 1) +"]");
                System.out.println("Skip at index " + i);
                continue;  // 防止重复
            }
            if (visited[i]){
                System.out.println("already visit index " + i);
                continue;
            }
            visited[i] = true;
            permuteList.add(nums[i]);
            backtracking(permuteList, permutes, visited, nums);
            permuteList.remove(permuteList.size() - 1);
            visited[i] = false;
        }
    }

    private void print(boolean[] hasVisited){
        for(boolean i : hasVisited){
            System.out.print(i + " ");
        }
        
        System.out.println();
    }
}

public class problem_47{
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.permuteUnique(new int[]{1,2,1});
    }
}