public class problem13{
    public static int romanToInt(String s) {
        int ans = 0;
        if(s.length() == 0) return 0;

        for(int i = 0; i < s.length(); i++){
            switch(s.charAt(i)){
                case 'M':
                    ans += 1000;
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'C':
                    if(i + 1 < s.length() && s.charAt(i + 1) == 'M'){
                        ans += 900;
                        i++;
                    }else if(i + 1 < s.length() && s.charAt(i + 1) == 'D'){
                        ans += 400;
                        i++;
                    }else{
                        ans += 100;
                    }
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'X':
                    if(i + 1 < s.length() && s.charAt(i + 1) == 'C'){
                        ans += 90;
                        i++;
                    }else if(i + 1 < s.length() && s.charAt(i + 1) == 'L'){
                        ans += 40;
                        i++;
                    }else{
                        ans += 10;
                    }
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'I':
                    if(i + 1 < s.length() && s.charAt(i + 1) == 'X' ){
                        ans += 9;
                        i++;
                    }else if(i + 1 < s.length() && s.charAt(i + 1) == 'V'){
                        ans += 4;
                        i++;
                    }else{
                        ans += 1;
                    }
                    break;
                default:
                    System.out.println("Input error");
                    return 0;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println(romanToInt("MCMXCIV"));
    }
}