public class problem8{
    public static int myAtoi(String str) {
        boolean is_valid_digit = true;
        int sign = 1;
        String number_to_convert = "";
        int index = 0;
        boolean already_signed = false;

        while(is_valid_digit && index < str.length()){
            if(str.charAt(index) == ' '){

            }else if(str.charAt(index) == '+'){
                if(!already_signed){
                    already_signed = true;
                }else{
                    return 0;
                }
            }else if(str.charAt(index) == '-'){
                if(!already_signed){
                    sign = -1;
                    already_signed = true;
                }else return 0;
            }else if(str.charAt(index) - '0' >= 0 && str.charAt(index) - '0' < 10){
                number_to_convert += str.charAt(index);
            }else{
                is_valid_digit = false;
            }
            index ++ ;
        }
        System.out.println(sign + " " + number_to_convert);

        //return 0;
        if(number_to_convert.length() == 0){
            return 0;
        }else{
            return string_to_int(sign, number_to_convert);
        }
    }
    
    public static int string_to_int(int sign, String s){
        int index = 0;
        int ans = 0;
        while(index < s.length()){
            int each_digit = s.charAt(index) - '0';
            if(ans * sign > Integer.MAX_VALUE/10){
                return Integer.MAX_VALUE;
            }else if(ans * sign < Integer.MIN_VALUE/10){
                return Integer.MIN_VALUE;
            }
            ans = ans * 10 + each_digit;
            index ++;
        }
        return ans*sign;
    }


    public static void main(String[] args) {
        System.out.println(myAtoi("   +   0 1 2 3"));
    }
}