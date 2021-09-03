class Algothrim{
    public void quick_sort(int[] arr){
        quick_sort_helper(arr, 0, arr.length - 1);
    }

    public void quick_sort_helper(int[] arr, int l, int r){
        if(l >= r) return;
        
        int piviot = partition(arr, arr[r], l, r);
        quick_sort_helper(arr, l, piviot - 1);
        quick_sort_helper(arr, piviot + 1, r);
    }

    public int partition(int[] arr, int target, int l, int r){
        int i = l;
        int j = r - 1;
        
        while(true){
            while(arr[i] <= target && i < r){
                i ++;
            }

            while(arr[j] >= target && j > i){
                j --;
            }

            if(i >= j){
                break;
            }

            swap(arr, i, j);
        }
    
        if (i < r) swap(arr, i, r);
        return i;

    }

    public void swap(int[] arr, int l, int r){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
    }

    public void print(int[] arr){
        for(int i : arr){
            System.out.print(i + " ");
        }

        System.out.println();
    }
}

public class quick_sort{
    public static void main(String[] args) {
        Algothrim qs = new Algothrim();
        int[] test = new int[] {1, 2, 3, 4, 5, 6, 7};
        qs.quick_sort(test);
        qs.print(test);
    }
}