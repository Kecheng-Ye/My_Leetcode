import java.util.*;

public class sliding {
    public String macthString(String s, String t){
        int start = 0;
        int minLen = Integer.MAX_VALUE;
        int left = 0;
        int right = 0;

        HashMap<Character, Integer> window = new HashMap<>();
        HashMap<Character, Integer> need = new HashMap<>();

        int match_num = 0;

        for(char a : t.toCharArray()){
            need.put(a, need.getOrDefault(a, 0) + 1);
        }

        while(right < s.length()){
            char current = s.charAt(right);

            if(need.containsKey(current)){
                window.put(current, window.getOrDefault(current, 0) + 1);

                if(window.get(current) == need.get(current)) match_num ++;
            }

            right++;

            while(match_num == t.length()){
                if(right - left < minLen){
                    start = left;
                    minLen = right - left;
                }

                char delete_char = s.charAt(left);

                if(need.containsKey(delete_char)){
                    window.put(delete_char, window.get(delete_char) - 1);

                    if(window.get(delete_char) < need.get(delete_char)) match_num --;
                }

                left ++;
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
    }
}