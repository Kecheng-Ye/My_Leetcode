import java.util.*;

public class Problem47{
    public static void main(String[] args) {
        int[] nums = {2,2,1,1};
        System.out.println(permuteUnique(nums));
    }

    public static List<List<Integer>> permuteUnique(int[] nums) {
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
            //System.out.println("pre answer: "+curr_perm+" One answer: "+one_ans);
            ans.add(one_ans);
            return;
        }

        List<Integer> temp_cand = new ArrayList<>(candidates);
        //System.out.println(temp_cand);
        for(int i = 0; i < candidates.size(); i++){
            int temp = candidates.get(i);
            temp_cand.remove(i);
            if(i != 0 && temp_cand.contains((Integer) temp) && (temp_cand.indexOf((Integer) temp) < i)){
                //System.out.println(candidates + " " + i + "th" + " get skipped");
                temp_cand.add(i, temp);
                continue;
            }
            curr_perm.add(temp);
            Helper(temp_cand, curr_perm, ans);
            curr_perm.remove(curr_perm.size()-1);
            temp_cand.add(i, temp);
        }
    }
}