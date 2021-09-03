import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        if(people.length == 0) return new int[0][0];

        Arrays.sort(people, (arr1, arr2) -> ((arr1[0] == arr2[0]) ? arr1[1] - arr2[1] : -(arr1[0] - arr2[0])));

        ArrayList<int[]> ans = new ArrayList<>();
        for(int[] i : people){
            ans.add(i[1], i);
        }

        return ans.toArray(new int[people.length][]);
    }
}