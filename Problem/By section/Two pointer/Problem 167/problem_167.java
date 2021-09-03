public class problem_167 {
    // time: O(n^2), space: O(1)
    // public int[] twoSum(int[] numbers, int target) {
    //     for(int i = 0; i < numbers.length - 1; i++){
    //         for(int j = i + 1; j < numbers.length && numbers[i] + numbers[j] <= target; j++){
    //             if(numbers[i] + numbers[j] == target){
    //                 return new int[]{i + 1, j + 1};
    //             }
    //         }
    //     }
    //     return new int[0];
    // }
    
    // time: O(N), space: O(1)
    public int[] twoSum(int[] numbers, int target) {
        // left pointer i; right pointer j
        int i = 0;
        int j = numbers.length - 1;

        while(i < j){
            int left_num = numbers[i];
            int right_num = numbers[j];

            // if the two number sum is equal to the target 
            if(left_num + right_num == target){
                return new int[]{i + 1, j + 1};
            }else if(left_num + right_num > target){
                // if the two number sum is greater to the target 
                // decrement the large number pointer  
                j --;
            }else{
                // if the two number sum is smaller to the target 
                // increment the large number pointer
                 i ++;
            }
        }
        return new int[0];
    }


}