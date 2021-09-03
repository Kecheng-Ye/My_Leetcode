class Algothrim{

    // public void merge_sort(int[] arr){
    //     int[] ans = helper(arr, 0 , arr.length - 1); 
        
    //     int i = -1;
    //     while(i++ < arr.length - 1){
    //         arr[i] = ans[i];
    //     }
    // }

    // public int[] helper(int[] arr, int i, int j){
    //     if(i == j) return new int[]{arr[i]};


    //     int[] left = helper(arr, i, (int)(i + j)/2);
    //     int[] right = helper(arr, (int)(i + j)/2 + 1, j);
        
    //     return merge(left, right);
    // }


    // public int[] merge(int[] left, int[] right){
    //     int i = 0;
    //     int j = 0;
    //     int temp = 0;
    //     int[] ans = new int[left.length + right.length];

    //     while(i < left.length || j < right.length){
    //         if(i == left.length){
    //             ans[temp++] = right[j++];
    //         }else if(j == right.length){
    //             ans[temp++] = left[i++];
    //         }else{
    //             if(left[i] > right[j]){
    //                 ans[temp] = right[j];
    //                 j ++;
    //             }else{
    //                 ans[temp] = left[i];
    //                 i ++;
    //             }
    //             temp ++;
    //         }
    //     }

    //     return ans;
    // }

    public int[] ans;

    public void print(int[] arr){
        for(int i : arr){
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public void merge_sort(int[] arr){
        ans = new int[arr.length];

        helper(arr, 0, arr.length - 1);
    }

    public void helper(int[] arr, int left, int right){
        if(left >= right) return;

        int mid = left + (right - left)/2;
        helper(arr, left, mid);
        helper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    public void merge(int[] arr, int left, int mid, int right){
        for(int k = left; k <= right; k ++){
            ans[k] = arr[k];
        }

        int i = left; 
        int j = mid + 1;

        for(int k = left; k <= right; k ++){
            if(i > mid){
                arr[k] = ans[j++];
            }else if(j > right){
                arr[k] = ans[i++];
            }else{
                if(ans[i] > ans[j]){
                    arr[k] = ans[j++];
                }else{
                    arr[k] = ans[i++];
                }
            }
        }
    }
}

public class merge_sort{
    public static void main(String[] args) {
        int[] test = new int[]{-1,-2,-100,100,98};
        Algothrim alg = new Algothrim();
        alg.merge_sort(test);
        alg.print(test);
    }
}