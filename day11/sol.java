class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        
        
         if(image[sr][sc] == newColor)
            return image;
        flood_fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    
    void flood_fill(int[][] image,int r , int c, int newColor, int oldColor){
        
        if(r<0  || c<0 || r>=image.length || c>= image[0].length || oldColor != image[r][c])
         return;
        image[r][c] = newColor;//for coloring
        flood_fill(image, r+1, c,newColor, oldColor);
        flood_fill(image, r-1, c,newColor, oldColor);
        flood_fill(image, r, c+1,newColor, oldColor);
        flood_fill(image, r, c-1,newColor, oldColor);
    }
}