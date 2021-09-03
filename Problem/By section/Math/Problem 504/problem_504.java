class Solution {
    // Time: O(logn), Space: O(1)
    public String convertToBase7(int num) {
        if(num == 0) return "0";

        boolean is_negative = (num < 0);
        num = is_negative ? -num : num;
        StringBuilder builder = new StringBuilder();
        
        while(num > 0){
            builder.append(num % 7);
            num = (num / 7);
        }

        String ans = builder.reverse().toString();

        return is_negative ? "-" + ans : ans;
    }
}

public class problem_504{
    public static void main(String[] args) {
        
    }
}