public class problem_167 {
    public int[] twoSum(int[] numbers, int target) {
        for(int i = 0; i < numbers.length - 1; i++){
            for(int j = i + 1; j < numbers.length && numbers[i] + numbers[j] <= target; j++){
                if(numbers[i] + numbers[j] == target){
                    return new int[]{i , j};
                }
            }
        }
        return new int[0];
    }

}