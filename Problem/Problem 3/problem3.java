public class problem3{
    public static int lengthOfLongestSubstring(String s) {
        int[] frequency = new int[200];
        int longest_length = 0;
        int i = 0;
        int j = 0;
        // for(int i = 0; i < s.length(); i++){   
        //     //System.out.println("checking char "+ s.charAt(i) +" at " + i);
        //     int this_character = (int)(s.charAt(i) - ' ');
        //     if(frequency[this_character] == 0){
        //         frequency[this_character]++;
        //         curr_length++;
        //         longest_length = Math.max(longest_length, curr_length);
        //         //System.out.println("Still a non repeating substring with " + curr_length + " " + longest_length);
        //     }else{
        //         //System.out.println("A repating char " + s.charAt(i));
        //         prev_index++;
        //         frequency = new int[200];
        //         i = prev_index - 1;
        //         curr_length = 0;
        //         continue;
        //     }
        // }
        while(i < s.length() && j < s.length()){    //we always check the range from [i,j]
            int this_character = (int)(s.charAt(j) - ' '); //check the jth char to determine wheher the string si valid or not 
            //System.out.println("checking char "+ s.charAt(j));
            if(frequency[this_character] == 0){
                j++;                        //increment the j since it is still a none-repeating substring
                frequency[this_character]++;
                longest_length = Math.max(longest_length, j-i);
               // System.out.println("Still a non repeating substring with " + (j-i) + " " + longest_length);
            }else{
                int start_of_the_window = (int)(s.charAt(i++) - ' '); //extend the i when meets a repetition
                // System.out.println("A repating char " + s.charAt(j-1));
                // System.out.println("starting checking at " + i);
                frequency[start_of_the_window]--;
            }
        }

        return longest_length;
    }

    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("dvdf"));
    }   

}