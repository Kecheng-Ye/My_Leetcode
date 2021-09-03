import java.util.*;

class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> curr_ans = new ArrayList<>(); 
        for(int i = 0; i < input.length(); i ++){
            char temp = input.charAt(i);
            if(temp == '+' || temp == '-' || temp == '*' ){

                List<Integer> left = diffWaysToCompute(input.substring(0, i));
                List<Integer> right = diffWaysToCompute(input.substring(i + 1, input.length()));

                for(int l : left){
                    for(int r : right){
                        switch(temp){
                            case '+':
                                curr_ans.add(l + r);
                                break;
                            case '-':
                                curr_ans.add(l - r);
                                break;
                            case '*':
                                curr_ans.add(l * r);
                                break;
                        }
                    }
                }
            }
        }
        
        
        return (curr_ans.size() == 0) ? Arrays.asList(Integer.parseInt(input)) : curr_ans;
    }
}