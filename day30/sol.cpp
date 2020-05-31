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
    int kthSmallest(TreeNode* root, int k) {
         
        int count = 0;
        int result = 0;
        kthInorder(root, k, count, result);
        return result;
    }
    
    void kthInorder(TreeNode* root, int k, int& count, int& result){
        if(root -> left)
            kthInorder(root -> left, k, count, result);
        count ++;
        if (count == k){
            result = root-> val;
            return;
        }
        if(root -> right)
            kthInorder(root -> right, k, count, result);
    }
};