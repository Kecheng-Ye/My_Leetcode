public class problem6{

    public static String convert(String s, int numRows) {
        if(s.length() == 0) return "";
        if(numRows == 1) return s;
        if(s.length() < numRows) return s;
        
        int total_divide = numRows + (numRows - 2);
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < numRows; i++){
            for(int j = i; j < s.length(); j += total_divide){
                builder.append(s.charAt(j));
                if(i != 0 && i != numRows - 1 && j + total_divide - 2*i < s.length()){    //if it is not the first or last row
                    builder.append(s.charAt(j + total_divide - 2*i));                     //append the j + total_divide - 2*i to the next
                }
            }
        }

        return builder.toString();
    }

    public static void main(String[] args) {
        System.out.println(convert("Abcd",1));
    }
}