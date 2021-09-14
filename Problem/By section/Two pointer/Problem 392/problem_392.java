class Solution {
    // Time: O(n), Space: O(1) 
    public boolean isSubsequence(String s, String t) {
        // my approach

        // int i = 0;
        // int j = 0;
        
        // while(i < s.length() && j < t.length()){
        //     char temp_1 = s.charAt(i);
        //     char temp_2 = t.charAt(j);
            
        //     if(temp_1 == temp_2){
        //         i++;
        //     }
            
        //     j++;
        // }
        
        // return i == s.length();

        /********************************************/
        // can be accelerate by using index of 
        int index = -1;
        for (char c : s.toCharArray()) {
            index = t.indexOf(c, index + 1);
            if (index == -1) {
                return false;
            }
        }
        return true;
    }
}