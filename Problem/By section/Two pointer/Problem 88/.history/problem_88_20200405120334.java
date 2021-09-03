class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // two pointer
        // should start at end since 
        // if we start at head, it will overwrite the unused data
        int i = m - 1;
        int j = n - 1;
        int ans_index = m + n - 1;
        
        // iterating all of the element in both nums1 and nums2
        while(i >= 0 || j >= 0){
            // if we has reach end of original nums1
            // just add the nums2 to the rest of nums1
            if(i < 0){
                nums1[ans_index --] = nums2[j --];
            }else if(j < 0){
                // if we has reach end of original nums2
                // just add the nums1 to the rest of nums1
                nums1[ans_index --] = nums1[i --];
            }else if(nums1[i] > nums2[j]){
                // if the number in nums1 is bigger than the number in nums2
                // add the number to nums1 and decrement i 
                nums1[ans_index --] = nums1[i --];
            }else{
                // if the number in nums2 is bigger than the number in nums1
                // add the number to nums1 and decrement j
                nums1[ans_index --] = nums2[j --];
            }
        }
    }
}

public class problem_88{
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.merge(new int[]{2, 0}, 1, 
                  new int[]{1}, 1);
    }
}