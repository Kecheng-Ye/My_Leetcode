import java.util.*;
import java.util.Arrays;
import java.util.List;

public class problem40{
    public static void main(String[] args) {
        int[] candidates = {10,1,2,7,6,1,5};
        System.out.println(combinationSum2(candidates, 8));
    }

    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> answer = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        combinationSum2_helper(candidates, target, target, -1, comb, answer);
        return answer;
    }
    
    public static void combinationSum2_helper(int[] candidates, int target, int curr, int index, List<Integer> comb,List<List<Integer>> answer){

        for(int i = index+1; i < candidates.length ; i++){
            if(i != 0 && i > index+1 && candidates[i] == candidates[i-1]){
                continue;
            }
            List<Integer> temp = new ArrayList(comb);
            temp.add(candidates[i]);
            if(curr == candidates[i]){
                answer.add(new ArrayList<Integer>(temp));
                return;
            }

            if(curr - candidates[i] < 0){
                return;
            }
            combinationSum2_helper(candidates, target, curr-candidates[i], i, temp, answer);
            temp.remove((Integer) candidates[i]);
        }
    }


}