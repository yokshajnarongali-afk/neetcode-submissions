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
int helper (TreeNode* root , int maxi)
{
    if (!root) return 0 ;
    int gn = 0 ;

    if (root -> val >= maxi) gn++ ; 

    maxi = max (maxi , root -> val) ;

    int l = helper (root -> left , maxi) ;
    int r = helper (root -> right , maxi) ;

    return gn + l + r ;
}

int goodNodes (TreeNode* root)
{
    return helper (root , root -> val) ;
}
};
