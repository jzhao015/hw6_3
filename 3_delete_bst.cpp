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
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root) //check if root exist 
            if(key < root->val) root->left = deleteNode(root->left, key); /*if the key we want to delete is less then the root's value, we call deleteNode function recursively and root keeps pointing to the left until we find the node*/  
        
            else if(key > root->val) root->right = deleteNode(root->right, key); /*the key is larger than the root's value, we go through the right and call deleteNode recursively untill we find the node*/
            else{
                if(!root->left && !root->right) return NULL;   //if no left and right child, we return null
                if (!root->left || !root->right) //if only one child
                    return root->left ? root->left : root->right;   //return the node with child   
                
					                                                  
                TreeNode* temp = root->left; /* for two children exist, create a temp treenode pointer points to the root's left */            
                while(temp->right != NULL) temp = temp->right;  /*temp keeps pointing to right untill the temp's right is null */
                root->val = temp->val;     //    assign the temp's value to root
                root->left = deleteNode(root->left, temp->val);  //     delete left 
            }
        return root;
    }
};
