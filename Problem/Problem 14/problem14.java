public class problem14{
    //time complexcity O(nm) 
    //n = length of the string list
    //m = the string length of the list[0]
    public static String longest_common_header(String[] list){
        if(list.length == 0) return "";

        if(list.length == 1) return list[0];

        String ans = list[0];
        int index = 1;
        while(ans.length() != 0 && index < list.length){
            if(list[index].length() == 0) return "";
            //int max_length = Math.min(ans.length(), list[index].length());
            for(int i = 0; i < ans.length(); i++){
                if(i == list[index].length() || ans.charAt(i) != list[index].charAt(i)){
                    //System.out.println("i= " + i);
                    ans = ans.substring(0, i);
                    //System.out.println("new header equals " + ans);
                    break;
                }
            }
            index ++;
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println(longest_common_header(new String[]{"dog","racecar","car"}));
    }
}