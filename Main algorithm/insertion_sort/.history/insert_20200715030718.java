public class insert {
    
    public void sort(int[] arr){
        for(int i = 1; i < arr.length; i++){
            int j;

            for(j = 0; j < i && arr[j] < arr[i]; j++){}

            while(j <= i){
                swap(arr, j++, i);
            }
        }
    }

    public void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

}