class Algothrim{

    public void merge_sort(int[] arr){
        arr = helper(arr, 0 , arr.length - 1);
    }

    public int[] helper(int[] arr, int i, int j){
        if(i == j) return new int[]{arr[i]};


        int[] left = helper(arr, i, (int)(i + j)/2);
        int[] right = helper(arr, (int)(i + j)/2 + 1, j);

        return merge(left,right);
    }

    public int[] merge(int[] left, int[] right){
        int i = 0;
        int j = 0;
        int temp = 0;
        int[] ans = new int[left.length + right.length];

        while(i <= left.length || j <= left.length){
            if(i == left.length){
                ans[temp++] = right[j++];
            }else if(j == right.length){
                ans[temp++] = left[i++];
            }else{
                if(left[i] > right[j]){
                    ans[temp] = right[j];
                }else{
                    ans[temp] = right[i];
                }
                temp ++;
            }
        }

        return ans;
    }
}