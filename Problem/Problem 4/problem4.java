public class problem4{
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums1.length == 0){
            return (nums2.length % 2 == 0) ? (nums2[nums2.length/2 - 1] + nums2[nums2.length/2])/2 : nums2[(nums2.length + 1)/2 -1];
        }

        if(nums2.length == 0){
            return (nums1.length % 2 == 0) ? (nums1[nums1.length/2 - 1] + nums1[nums1.length/2])/2 : nums1[(nums1.length + 1)/2 -1];
        }

        int ileft = 0;
        int iright = nums1.length;
        while(ileft <= iright){
            int imiddle = (ileft + iright)/2;
            //System.out.println("imiddle: " + imiddle + " " + nums1[imiddle]);
            int jmiddle = (int)(nums1.length + nums2.length + 1)/2 - imiddle;  
            //System.out.println("jmiddle: " + jmiddle + " " +nums2[jmiddle]);
            if(nums2[jmiddle-1] > nums1[imiddle] && imiddle < iright){
                ileft++;
            }else if(nums1[imiddle - 1] > nums2[jmiddle] && imiddle > ileft){
                iright--;
            }else{
                //System.out.println(imiddle + " " + jmiddle);
                int max_of_left = 0;
                int min_of_right = 0;
                if(imiddle == 0){
                    max_of_left = nums2[jmiddle - 1];
                }else if(jmiddle == 0){
                    max_of_left = nums1[imiddle - 1];
                }else{
                    max_of_left = Math.max(nums2[jmiddle - 1],nums1[imiddle - 1]);
                }
                if((nums1.length + nums2.length) % 2 == 1) return max_of_left;

                if(imiddle - 1 == nums1.length){
                    min_of_right = nums2[jmiddle];
                }else if(jmiddle - 1 == nums2.length){
                    min_of_right = nums1[imiddle];
                }else{
                    min_of_right = Math.min(nums2[jmiddle], nums1[imiddle]);
                }

                return (max_of_left + min_of_right) / 2;
            }
        }
        return 0.0;
    }


    public static void main(String[] args) {
        int[] arr1 = {1,3};
        int[] arr2 = {2};
        
        //System.out.println(arr1.length + " " + arr2.length);

        System.out.println(findMedianSortedArrays(arr1,arr2));
    }
}