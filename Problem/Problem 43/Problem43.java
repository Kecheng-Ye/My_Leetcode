
public class Problem43{
    public static void main(String[] args) {
        String a = "123456789";
        String b = "987654321";
        System.out.println(multiply(a,b));
    }
 
    // public static String multiply(String num1, String num2) {
    //     if(num1.equals("0") || num2.equals("0")){
    //         return "0";
    //     }

    //     int[] arr1 = comvert_to_arr(num1);
    //     int[] arr2 = comvert_to_arr(num2);

    //     int num = 0;
    //     for(int i : arr2){
    //         for(int j : arr1){
    //             num += i*j;
    //         }
    //     }
    //     System.out.println(num);
    //     StringBuilder builder = new StringBuilder();
    //     while(num > 0){
    //         int digit = num % 10;
    //         builder.insert(0, digit);
    //         num = num / 10;
    //     }

    //     return builder.toString();
    // }

    // public static int[] comvert_to_arr(String num1){
    //     int[] ans = new int[num1.length()];
    //     for(int i = num1.length()-1; i >= 0; i--){
    //         ans[num1.length()-1 - i] = (int)((int)(num1.charAt(i) - '0') * Math.pow(10, num1.length()-1 - i));
    //     }
    //     return ans;
    // }

    public static String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) return "0";

        int[] ans = new int[num1.length() + num2.length()];
        for(int i = num1.length() - 1; i >= 0; i--){
            for(int j = num2.length() - 1; j >= 0; j--){
                int product = (int)(num1.charAt(i) - '0') * (int)(num2.charAt(j) - '0');
                int front = i + j;
                int back = front + 1;
                int temp_sum = product + ans[back];
                ans[back] = temp_sum % 10;
                ans[front] += (int) temp_sum / 10;
            }
        }

        StringBuilder builder = new StringBuilder();
        for(int digit : ans){
            if(!(digit == 0 && builder.length() == 0)){
                builder.append(digit);
            }
        }

        return (builder.length() == 0) ? "0" : builder.toString();
    }
}