class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
     ArrayList<Integer>[] adj = new ArrayList[numCourses] ;
     for (int i =0; i< numCourses; ++i)
         adj[i] = new ArrayList();
        
        for(int[] pre : prerequisites)
            adj[pre[0]].add(pre[1]);
        
        int[] visited = new int[numCourses];
        for(int i= 0; i< numCourses; ++i)
            if(visited[i] == 0 && !dfs(adj, visited, i))
                return false;
        return true;
    }
    
    private boolean dfs(ArrayList<Integer>[] adj, int[] visited, int v){
        if(visited[v] ==1)
            return false;
        visited[v] =1;
        for(int ad : adj[v])
            if(!dfs(adj, visited , ad))
                return false;
        visited[v] =2;
        
        return true;
    }
}