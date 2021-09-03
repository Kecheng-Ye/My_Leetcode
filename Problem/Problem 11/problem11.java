public class problem11{
    public static int maxArea(int[] height) {
        int max_area = 0;
        int left = 0;
        int right = height.length - 1;

        //two pointer approach
        while(left < right){
            //we first calculate the current area
            int current_area = Math.min(height[left], height[right]) * (right - left);
            max_area = (current_area > max_area) ? current_area : max_area;
            //then we move the smaller side inside to try to reach a new max
            if(height[left] > height[right]){
                right--;
            }else{
                left++;
            }
        }

        return max_area;
    }

    public static void main(String[] args) {
        System.out.println(maxArea(new int[]{1,8,6,2,5,4,8,3,7}));
    }
}