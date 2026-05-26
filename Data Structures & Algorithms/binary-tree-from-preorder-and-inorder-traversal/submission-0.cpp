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
TreeNode* helper(vector<int>& preorder, vector<int>& inorder , int& preIdx , int l , int r , unordered_map<int , int>& m)
{
    if (l > r) return NULL ;

    int val = preorder[preIdx] ;
    preIdx ++ ;

    TreeNode* root = new TreeNode (val) ;

    int inIdx = m[val] ;

    root -> left = helper (preorder , inorder , preIdx , l , inIdx-1 , m) ;
    root -> right = helper (preorder , inorder , preIdx , inIdx+1 , r , m) ;

    return root ;
}

TreeNode* buildTree (vector<int>& preorder, vector<int>& inorder)
{
    unordered_map<int , int> m ;

    for (int i=0 ; i<inorder.size () ; i++)
    {
        m[inorder[i]] = i ;
    }

    int preIdx = 0 ;

    return helper (preorder , inorder , preIdx , 0 , inorder.size ()-1 , m) ;
}
};
