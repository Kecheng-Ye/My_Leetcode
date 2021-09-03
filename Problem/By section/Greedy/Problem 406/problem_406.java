import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    // Time: O(nlogn), Space: O(n)
    public int[][] reconstructQueue(int[][] people) {
        if(people.length == 0) return new int[0][0];

        // sort the people array by its height in descending order
        // if meet people with same height, sort them by their second index in increasing order
        Arrays.sort(people, (arr1, arr2) -> ((arr1[0] == arr2[0]) ? arr1[1] - arr2[1] : -(arr1[0] - arr2[0])));

        // start with the highest people
        // insert them by the second index
        // since the height is from high to low
        // we will always construct a valid subarray with
        // the element add as the shorest people
        ArrayList<int[]> ans = new ArrayList<>();
        for(int[] i : people){
            ans.add(i[1], i);
        }

        return ans.toArray(new int[people.length][]);
    }
}