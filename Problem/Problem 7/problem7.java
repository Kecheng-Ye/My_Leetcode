public class problem7{

    public static int reverse(int x) {
        int each_digit = 0;
        int ans = 0;
        int sign = (x >= 0) ? 1 : -1;
        x = Math.abs(x); 
        while(x > 0){
            each_digit = x % 10;
            System.out.println(x + " " + each_digit);
            if(sign * ans > (Integer.MAX_VALUE)/10  || sign * ans < (Integer.MIN_VALUE)/10){
                return 0;
            }
            ans = ans * 10 + each_digit;
            x = (int)(x / 10);
        }        

        return ans * sign;
    }

    public static void main(String[] args) {
        System.out.println(reverse(1534236469));
    }
}