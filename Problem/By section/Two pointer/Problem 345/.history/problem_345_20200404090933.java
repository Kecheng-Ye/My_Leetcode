import java.util.*;
class problem_345 {
    public static String reverseVowels(String s) {
        if(s.length() == 0) return null;
        if(s.length() == 1) return s;
        
        int i = 0;
        int j = s.length() - 1;
        char[] ans = s.toCharArray();
        HashSet<Character> Vowels = new HashSet<Character>();
        Vowels.add('a');
        Vowels.add('e');
        Vowels.add('i');
        Vowels.add('o');
        Vowels.add('u');
        // Vowels.addAll(Arrays.asList(new char[]{'a', 'e', 'i', 'o', 'u'}));
        // Collections.addAll(Vowels, new char[]{'a', 'e', 'i', 'o', 'u'});
        boolean left_flag = false;
        boolean right_flag = false;
        
        // while(i < j){
        //     System.out.println(i + " " + j);
        //     if(left_flag && right_flag){
        //         char temp = ans[i];
        //         ans[i] = ans[j];
        //         ans[j] = temp;
        //         System.out.println("before swap: " + i + " " + j);
        //         i ++;
        //         j --;
        //         left_flag = Vowels.contains(ans[j]);
        //         right_flag = Vowels.contains(ans[i]);
        //         System.out.println("after swap: " + i + " " + j);
        //     }else if(Vowels.contains(ans[i])){
        //         left_flag = true;
        //         j = (right_flag) ? j : j - 1;
        //     }else if(Vowels.contains(ans[j])){
        //         right_flag = true;
        //         i = (left_flag) ? i : i + 1;
        //     }else{
        //         i ++;
        //         j --;
        //     }
        // }

        while(i < j){
            if(Vowels.contains(ans[i]) && Vowels.contains(ans[j])){
                char temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
                i ++;
                j --;
            }else if(Vowels.contains(ans[i])){
                j --;
            }else if(Vowels.contains(ans[j])){
                i ++;
            }else{
                i ++;
                j --;
            }
        }
        
        return new String(ans);
    }

    public static void main(String[] args) {
        System.out.println(reverseVowels("leetcode"));
    }
}