public class selection_sort {
    
    public static void sort(int[] array){
        // for(int i = 0; i < arr.length - 1; i ++){
        //     int min_index = i;

        //     for(int j = i + 1; j < arr.length; j ++){
        //         if(arr[j] < arr[min_index]) min_index = j;
        //     }

        //     if(min_index != i){
        //         int temp = arr[i];
        //         arr[i] = arr[min_index];
        //         arr[min_index] = temp;
        //     }
        // }


        int i, j, k;
        for (i=0; i< array.length-1; i++) {
            j=i;
            for (k=i+1; k< array.length k++)
            if (array[k] < array[j]) j=k;
            if (j!=i) swap(array, i, j);
        }
    }

    public static void main(String[] args) {
        int[] arr = {1};

        sort(arr);

        for(int i : arr) System.out.print(i);
    }
}