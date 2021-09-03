class Algothrim{
    public void quick_sort(int[] arr){
        quick_sort_helper(arr, 0, arr.length - 1);
    }

    public void quick_sort_helper(int[] arr, int l, int r){
        // if the left pointer is larger or bigger than the right pointer
        // meaning the partition for this l - r part is end
        if(l >= r) return;
        
        // find the piviot for the number in rth position
        int piviot = partition(arr, arr[r], l, r);

        // continue partition on the left part and right part
        quick_sort_helper(arr, l, piviot - 1);
        quick_sort_helper(arr, piviot + 1, r);
    }

    // the partition is to find the exact index of target number in arr
    public int partition(int[] arr, int target, int l, int r){
        // two pointer
        int i = l;
        int j = r - 1;
        
        while(true){
            // increment left pointer until it is bigger than target
            while(arr[i] <= target && i < r){
                i ++;
            }

            // decrement right pointer until it is smaller than target
            while(arr[j] >= target && j > i){
                j --;
            }

            // if the right pointer pass the left pointer 
            // meaning the piviot will be in between the two pointer
            if(i >= j){
                break;
            }

            // swap the element of i and j and continue partitioning
            swap(arr, i, j);
        }
        
        // make the piviot be placed in the index 
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
        int[] test = new int[] {3, 4, 5, 99, -1, -2, -100};
        qs.quick_sort(test);
        qs.print(test);
    }
}