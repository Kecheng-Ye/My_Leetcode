public class selection_sort {
    
    public static void sort(int[] arr){
        for(int i = 0; i < arr.length; i ++){
            int min_index = i;

            for(int j = i + 1; j < arr.length; j ++){
                if(arr[j] < arr[min_index]) min_index = j;
            }

            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,5,8,4,2,3};

        sort(arr);

        for(int i : arr) System.out.print(i + " ");
    }
}