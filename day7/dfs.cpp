/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
      int pX =0;
      int pY =0;
      int dX =-1; // it is uninitialised thats why -1 as it could be 0 or more when starting the tree
      int dY =-1;
        
      parentAndDepth(root, x, y, 0, dX,dY,pX,pY);
      return((dX == dY) && (pX != pY));  //returns true when both these conditions are true       
    }
    
    // auxiliary function for finding its parent and depth of its child as it will do the main backend job
    // d is level, dX is depth of child, pX is parent of x
    
    void parentAndDepth(TreeNode* root, int x, int y,int d , int& dX, int& dY, int& pX, int & pY){
        
        if(!root)    //if root is null then return
            return;
        if(root->left){
            //compare root's left with value of x
            if(root->left->val ==x){
                pX =root->val; //then root will get value as parent of x
                dX =d+1;  // depth of x will increase by 1   
            }else if(root->left->val == y){
                pY = root-> val;
                dY =d +1;   
            }
        }
        
          if(root->right){
            //compare root's right with value of x
            if(root->right->val ==x){
                pX =root->val; //then root will get value as parent of x
                dX =d+1;  // depth of x will increase by 1   
            }
              else if(root->right->val == y){
                pY = root-> val;
                dY =d +1;  
            }
        }
        //then we need to check if both x n y are found then we dont need to traverse further
        if(dX != -1 && dY != -1)
            return;  //that is we ghave found both of them
        
        //otherwise we'll again call the function and check for its child so d=d+1
        parentAndDepth(root->left, x, y, d+1, dX,dY,pX,pY);
        parentAndDepth(root->right, x, y,d+1, dX,dY,pX,pY);
      
           
        
    }
};