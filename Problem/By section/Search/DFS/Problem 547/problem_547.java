class Solution {
    // Time: O(w * h), Space: O(w)
    public int findCircleNum(int[][] M) {
        int count = 0;
        boolean[] isVisited = new boolean[M.length];
        
        for(int i = 0; i < M.length; i ++){
            if(!isVisited[i]){
                count++;
                DFS(M, i, isVisited);
            }
        }
        
        return count;
    }
    
    // think each friend is a node in a undirected graph
    // we will start at the first people
    // and mark it as visited
    // do dfs
    public void DFS(int[][] M, int f, boolean[] isVisited){
        if(isVisited[f]){
            return;
        }else{
            isVisited[f] = true;
            for(int i = 0; i < M[f].length; i ++){
                if(M[f][i] == 1){
                    DFS(M, i, isVisited);
                }
            }
        }
    }
}