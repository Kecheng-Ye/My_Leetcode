class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(n == 0) return;
        
        int i = 0, j = 0;
        while(i < m && j < n){
            int temp_1 = nums1[i];
            int temp_2 = nums2[j];
            if(temp_1 > temp_2){
                nums1[i] = temp_2;
                nums2[j] = temp_1;
                j ++;
            }else{
                i ++;
            }
        }

        for(int k = 0; k < n; k ++){
            nums1[m + k] = nums2[k];
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