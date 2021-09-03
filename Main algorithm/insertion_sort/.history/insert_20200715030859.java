public class insert {
    
    public static void sort(int[] arr){
        for(int i = 1; i < arr.length; i++){
            int j;

            for(j = 0; j < i && arr[j] < arr[i]; j++){}

            while(j <= i){
                swap(arr, j++, i);
            }
        }
    }

    public static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {9,8,7,6,5,4};

        sort(arr);

        for(int i : arr) System.out.print(i + " ");
    }

}