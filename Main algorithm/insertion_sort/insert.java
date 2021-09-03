public class insert {
    
    public static void sort(int[] arr){
        for(int i = 1; i < arr.length; i++){
            int temp = arr[i];
            int j = i-1;
            
            while (j >= 0 && arr[j] > temp) {
                arr[j+1] = arr[j];
                j--;
            }

            arr[j+1] = temp;
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