public class Algothrim{
    public void quick_sort(int[] arr){
        quick_sort_helper(arr, 0, arr.length);
    }

    public void quick_sort_helper(int[] arr, int l, int r){
        int piviot = partition(arr, arr[r], l, r);
        System.out.println(piviot);
    }

    public int partition(int[] arr, int target, int l, int r){
        int i = l;
        int j = r - 1;
        while(true){
            while(arr[i] <= target){
                i ++;
            }

            while(arr[j] >= target){
                j --;
            }

            if(i >= j){
                break;
            }

            swap(arr, i, j);
        }

        return (i == j) ? i + 1 : i;
    }

    public void swap(int[] arr, int l, int r){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }
}

public class quick_sort{
    public static void main(String[] args) {
        Algothrim qs = new Algothrim();
        qs.quick_sort(new int[] {1,2,3,4,0});
    }
}