# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        
        self.pX = 0  
        self.pY = 0
        self.dX = -1
        self.dY =-1
        self.parentAndDepth(root, x, y, 0)
        return((self.dX == self.dY) and (self.pX != self.pY))   
    
    
    # auxiliary function for finding its parent and depth of its child as it will do the main backend job
    # d is level, dX is depth of child, pX is parent of x
    
    def parentAndDepth(self, root: TreeNode, x: int, y: int, d: int) -> bool:
        
        if(root== None):    
            return
        if(root.left != None):
            #compare root's left with value of x
            if(root.left.val ==x):
                self.pX =root.val   #then root will get value as parent of x 
                self.dX=d+1         # depth of x will increase by 1   
            elif(root.left.val == y):
                self.pY = root.val#as pY is atomic so we cant assign integer value to it thus we need to write set
                self.dY = d +1   
          
               
        if(root.right  != None):
            #compare root's right with value of x
            if(root.right.val ==x):
                self.pX = root.val       #then root will get value as parent of x
                self.dX = d+1             # depth of x will increase by 1   
            elif(root.right.val == y):
                self.pY = root.val
                self.dY = d +1  
           
        #then we need to check if both x n y are found then we dont need to traverse further
        if(self.dX!= -1 and self.dY != -1):
            return  #that is we have found both of them
        
    #otherwise we'll again call the function and check for its child so d=d+1
        self.parentAndDepth(root.left, x, y, d+1)
        self.parentAndDepth(root.right, x, y,d+1)
      