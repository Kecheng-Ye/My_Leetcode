class Solution {
    // Time: O(n), Space: O(1)
    public String convertToTitle(int n) {
        if( n == 0) return "";
        // Because it starts from A, which is 1,
        // we have to decrement 1 for each time
        n --;
        return convertToTitle(n / 26) + (char)(n % 26 + 'A');
    }
}

public class problem_168{
    public static void main(String[] args) {
        
    }
}