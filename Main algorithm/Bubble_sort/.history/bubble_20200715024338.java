public class bubble{

    public void sort(int[] arr){
        for(int bound = arr.length - 1; bound >= 0; bound --){
            for(int i = 0; i < bound; i++){
                if(arr[i] > arr[i + 1]){
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }
    }


    public static void main(String[] args) {
        int[] arr = {2，1};
        bubble algo = new bubble();
        algo.sort(arr);
        for(int i : arr) System.out.print(i + " ");
    }
}