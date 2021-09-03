class Solution {
    // n = bit length of num
    // Time: O(n), Space: O(n)
    public String toHex(int num) {
        String hex_library = "123456789abcdef";
        if(num == 0) return "0";
        
        int temp = num;
        StringBuilder builder = new StringBuilder();
        while(temp > 0){
            builder.insert(0, hex_library.charAt(temp & 15));
            temp >>>= 4;
        }

        return builder.toString();
    }
}



