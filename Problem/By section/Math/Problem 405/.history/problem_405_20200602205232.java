class Solution {
    // n = bit length of num
    // Time: O(n), Space: O(n)
    public String toHex(int num) {
        // The decimal to hex library
        String hex_library = "0123456789abcdef";
        if(num == 0) return "0";
        
        int temp = num;
        StringBuilder builder = new StringBuilder();
        while(temp != 0){
            // every time we will get the last four bit of the temp
            // convert it to hex
            // and right shift for 4
            builder.insert(0, hex_library.charAt(temp & 15));
            temp >>>= 4;
        }

        return builder.toString();
    }
}



