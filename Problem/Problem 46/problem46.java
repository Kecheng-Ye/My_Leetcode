import java.util.*;

public class problem46 {
    public static void main(String[] args) {
        int[] nums = {1,2,3};
        System.out.println(permute(nums));
    }

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> candidates = new ArrayList<>();
        for(int i : nums){
            candidates.add(i);
        }
        Helper(candidates, new ArrayList<Integer>(), ans);
        return ans;
    }

    public static void Helper (List<Integer> candidates, List<Integer> curr_perm, List<List<Integer>> ans){
        if(candidates.size() == 1){
            List<Integer> one_ans = new ArrayList<>(curr_perm);
            one_ans.add(candidates.get(0));
            ans.add(one_ans);
            return;
        }

        List<Integer> temp_cand = new ArrayList<>(candidates);
        for(int i = 0; i < candidates.size(); i++){
            int temp = candidates.get(i);
            curr_perm.add(temp);
            temp_cand.remove((Integer) temp);
            Helper(temp_cand, curr_perm, ans);
            curr_perm.remove((Integer) temp);
            temp_cand.add(temp);
        }
    }
}