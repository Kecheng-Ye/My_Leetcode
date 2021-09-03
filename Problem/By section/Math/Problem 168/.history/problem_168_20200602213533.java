class Solution {
    public String convertToTitle(int n) {
        if( n == 0) return "";
        
        n --;
        return convertToTitle(n / 26) + (char)(n % 26 + 'A');
    }
}

public class problem_168{
    public static void main(String[] args) {
        System.out.println("aBC" + 'A');
    }
}