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

            }
        }

        return null;
    }
}