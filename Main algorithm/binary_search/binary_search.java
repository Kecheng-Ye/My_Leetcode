import java.util.ArrayList;

class algorithm{
    // Returns index of x if it is present in arr[l.. 
    // r], else return -1 
    int binarySearch(int arr[], int l, int r, int x){ 
        if (r >= l) { 
            int mid = l + (r - l) / 2; 
  
            // If the element is present at the 
            // middle itself 
            if (arr[mid] == x){
                return mid; 
            }
  
            // If element is smaller than mid, then 
            // it can only be present in left subarray 
            if (arr[mid] > x) 
                return binarySearch(arr, l, mid - 1, x); 
  
            // Else the element can only be present 
            // in right subarray 
            return binarySearch(arr, mid + 1, r, x); 
        } 
  
        // We reach here when element is not present 
        // in array 
        return -1; 
    }
    

    int binarySearch_leftbound(int arr[], int x){
        int l = 0;
        int r = arr.length - 1;
        
        while(l <= r){
            int mid = l + (r - l)/2 ;

            if(arr[mid] == x){
                r = mid - 1;
            }else if(arr[mid] > x){
                r = mid - 1;
            }else if(arr[mid] < x){
                l = mid + 1;
            }
        }

        if(l >= arr.length || arr[l] != x) return -1;

        return l;
    }

    int binarySearch_rightbound(int arr[], int x){
        int l = 0;
        int r = arr.length - 1;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(arr[mid] == x){
                l = mid + 1;
            }else if(arr[mid] > x){
                r = mid - 1;
            }else if(arr[mid] < x){
                l = mid + 1;
            }
        }

        if(r < 0 || arr[r] != x) return -1;

        return r;
    }
}

public class binary_search{
    public static void main(String[] args) {
        int[] arr = {1,1,2,2,3,4};
        algorithm bs = new algorithm();
        System.out.println(bs.binarySearch_rightbound(arr, 2));
    }
}