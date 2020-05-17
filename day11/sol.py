class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        
        if(image[sr][sc] == newColor):
            return image
        
        self.flood_fill(image, sr, sc, newColor, image[sr][sc])
        return image
    
    
    def flood_fill(self, image: List[List[int]], r: int, c: int, newColor: int ,oldColor: int):
        
        if(r<0  or c<0 or r>=len(image) or c>= len(image[0]) or oldColor != image[r][c]):
            return
        image[r][c] = newColor   #for coloring
        self.flood_fill(image, r+1, c,newColor, oldColor);
        self.flood_fill(image, r-1, c,newColor, oldColor);
        self.flood_fill(image, r, c+1,newColor, oldColor);
        self.flood_fill(image, r, c-1,newColor, oldColor);
        