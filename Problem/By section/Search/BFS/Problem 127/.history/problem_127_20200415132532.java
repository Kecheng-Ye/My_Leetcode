import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> wordSet = new HashSet<>();
        wordSet.addAll(wordList);
        if(! wordSet.contains(endWord)) return 0;
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        int step = 1;

        while( queue.size() != 0 ){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                String curString = queue.poll();

                if(curString.equals(endWord)) return step;

                for(String word : wordList){
                    if(!wordSet.contains(word) || ! can_convert(curString, word)){
                        continue;
                    }else{
                        queue.add(word);
                        wordSet.remove(word);
                        step++;
                    }
                }
            }
        }

        return -1;
    }

    public boolean can_convert(String a, String b){
        if(a.length() != b.length()) return false;
        
        int i = 0;
        int j = 0;
        int change = 0;

        while(i < a.length() && j < b.length()){
            if(a.charAt(i) != b.charAt(j)){
                change ++;
            }
            i ++;
            j ++;
        }

        return (change <= 1);
    }
}