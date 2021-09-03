class Solution {
    public char nextGreatestLetter(char[] letters, char target) {      
        return bin_search(letters, target, 0, letters.length - 1);
    }
    
    public char bin_search(char[] letters, char target, int l, int r){
        int middle = l + (r - l) / 2;
        System.out.println(l + " " + r + " " + middle);
        if(l > r || middle + 1 >= letters.length){
            return letters[0];    
        }
        
        if(letters[middle] <= target && letters[middle + 1] > target){
            return letters[middle + 1];
        }else if(letters[middle] < target){
            return bin_search(letters, target, middle + 1, r);
        }else{
            return bin_search(letters, target, l, middle - 1);
        }
    }
}

public class problem_744{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.nextGreatestLetter(new char[] {'e','e','e','n','n','n'}, 'e'));
    }
}