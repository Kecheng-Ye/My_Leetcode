import java.util.*;

class Solution {
    // memory for alreday calculated substring result 
    private HashMap<String, List<Integer>> map = new HashMap<>();
    
    // Time: O(w(1) * w(n - 1) + w(2) * w(n - 2) + ... + w(n - 1) * w(1))
    // Space: Same
    public List<Integer> diffWaysToCompute(String input) {
        // if we already calculate this expression
        // use it from the hashmap
        if(map.containsKey(input)) return map.get(input);
        
        // if not
        List<Integer> curr_ans = new ArrayList<>(); 
        for(int i = 0; i < input.length(); i ++){
            char temp = input.charAt(i);
            // we skip all the number till we get an operation
            if(temp == '+' || temp == '-' || temp == '*' ){
                
                // we enmuarate all the possible outcome from the leftside and rightside of the opearation 
                List<Integer> left = diffWaysToCompute(input.substring(0, i));
                List<Integer> right = diffWaysToCompute(input.substring(i + 1, input.length()));

                // then we combine these two subset to a new huge set
                // according to the opearator between them
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
        
        // important here!!!!
        // if we did not meet any opearator
        // meaning there is only number here
        curr_ans = (curr_ans.size() == 0) ? Arrays.asList(Integer.parseInt(input)) : curr_ans;

        // record the susbet for this input
        map.put(input, curr_ans);
        
        return curr_ans;
    }
}