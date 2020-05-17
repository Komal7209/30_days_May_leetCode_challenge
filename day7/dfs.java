/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
      AtomicInteger pX = new AtomicInteger();  //to pass it by reference
      AtomicInteger pY = new AtomicInteger();
      AtomicInteger dX = new AtomicInteger(-1); // it is uninitialised thats why -1 as it could be 0 or more when
      AtomicInteger dY =new AtomicInteger(-1);   //starting the tree
        
      parentAndDepth(root, x, y, 0, dX,dY,pX,pY);
      return((dX.get() == dY.get()) && (pX.get() != pY.get()));  //returns true when both these conditions are true       
    }
    
    // auxiliary function for finding its parent and depth of its child as it will do the main backend job
    // d is level, dX is depth of child, pX is parent of x
    
    void parentAndDepth(TreeNode root, int x, int y,int d, AtomicInteger dX, AtomicInteger dY, AtomicInteger pX, AtomicInteger pY){
        
        if(root==null)    //if root is null then return
            return;
        if(root.left != null){
            //compare root's left with value of x
            if(root.left.val ==x){
                pX.set(root.val); //then root will get value as parent of x 
                dX.set(d+1);  // depth of x will increase by 1   
            }else if(root.left.val == y){
                pY.set(root.val);   //as pY is atomic so we cant assign integer value to it thus we need to write set
                dY.set(d +1);   
            }
        }
        
          if(root.right  != null){
            //compare root's right with value of x
            if(root.right.val ==x){
                pX.set(root.val); //then root will get value as parent of x
               dX.set(d+1); // depth of x will increase by 1   
            }
              else if(root.right.val == y){
               pY.set(root.val);
                dY.set(d +1);  
            }
        }
        //then we need to check if both x n y are found then we dont need to traverse further
        if(dX.get() != -1 && dY.get() != -1)
            return;  //that is we ghave found both of them
        
        //otherwise we'll again call the function and check for its child so d=d+1
        parentAndDepth(root.left, x, y, d+1, dX,dY,pX,pY);
        parentAndDepth(root.right, x, y,d+1, dX,dY,pX,pY);
        
        
    }
}