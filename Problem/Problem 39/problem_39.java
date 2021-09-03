import java.util.*;

public class problem_39{
    public static void main(String[] args) {
        System.out.println(combinationSum(new int[] {2,3,6,7},7));
    }

    //The reason why it will duplicate the previous answer is that 
    //I dont put the attention on the index
    //just like the way combiantion works
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        ArrayList<List<Integer>> answer = new ArrayList<List<Integer>>();
        Arrays.sort(candidates);
        for(int i : candidates){
            ArrayList<Integer> curr_comb = new ArrayList<Integer>();
            curr_comb.add(i);
            combinationSumHelper(candidates, target, curr_comb, answer);
            curr_comb.remove((Integer)i);
        }

        return answer;
    } 

    public static void combinationSumHelper(int[] candidates, int target, List<Integer> curr_comb, ArrayList<List<Integer>> ans){
        if(sum(curr_comb) == target){
            //must initiate a new variable or the pointer will mess up
            ans.add(new ArrayList<Integer>(curr_comb));
            return;
        }

        ArrayList<Integer> temp = new ArrayList<>(curr_comb);
        for(int i : candidates){
            temp.add(i);
            if(sum(temp) > target){
                return;
            }else{
                combinationSumHelper(candidates, target, temp, ans);
            }
            temp.remove((Integer)i);
        }
    }

    public static int sum(List<Integer> curr_comb){
        int ans = 0;
        for(int i: curr_comb){
            ans += i;
        }
        return ans;
    }

   

    //correct answer!!!

    
    // List<List<Integer>> res=new ArrayList<>();
    // public List<List<Integer>> combinationSum(int[] candidates, int target) {
    //     List<Integer> list=new ArrayList<>();
    //     Arrays.sort(candidates);
    //     helper(candidates,list,target,0,0);
    //     return res;
    // }
    // public void helper(int[] candidates,List<Integer> list,int target,int sum,int index){
    //     if(sum>target)return;
    //     if(sum==target){
    //         res.add(new ArrayList<>(list));
    //         return;
    //     }
    //     for(int i=index;i<candidates.length;i++){
    //         if(sum+candidates[i]<=target){
    //            list.add(candidates[i]);
    //             helper(candidates,list,target,sum+candidates[i],i);
    //             list.remove(list.size()-1); 
    //         }else{
    //             break;
    //         }
                
    //     }
    // }
        
}
