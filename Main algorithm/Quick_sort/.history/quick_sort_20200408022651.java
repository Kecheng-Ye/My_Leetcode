class Algothrim{
    public void quick_sort(int[] arr){
        quick_sort_helper(arr, 0, arr.length - 1);
    }

    public void quick_sort_helper(int[] arr, int l, int r){
        System.out.println("Before l = " + l + " r = " + r);
        
        if(l >= r || l >= arr.length || r < 0){
            return;
        }
        int target = arr[r];
        int piviot = partition(arr, arr[r], l, r);
        System.out.println("Piviot for " + target + " is " + piviot);
        print(arr);
        quick_sort_helper(arr, l, piviot - 1);
        quick_sort_helper(arr, piviot + 1, r);
    }

    public int partition(int[] arr, int target, int l, int r){
        int i = l;
        int j = r - 1;
        while(true){
            System.out.println("Before i = " + i + " j = " + j);

            while(arr[i] <= target && i < r - 1){
                i ++;
            }

            while(arr[j] >= target && j > 0){
                j --;
            }

            System.out.println("After i = " + i + " j = " + j);
            
            if(i >= j){
                break;
            }

            swap(arr, i, j);
        }
        
        swap(arr, i, r);
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
        int[] test = new int[] {1,3,105,28,1000,13,-7,-100,9};
        qs.quick_sort(test);
        qs.print(test);
    }
}