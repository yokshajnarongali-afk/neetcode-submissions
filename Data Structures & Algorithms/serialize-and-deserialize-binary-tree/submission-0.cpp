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

class Codec {
public:

string serialize (TreeNode* root)
{
    if (!root) return "N," ;

    string s = to_string(root -> val) + "," ;

    s += serialize (root -> left) ;
    s += serialize (root -> right) ;

    return s ;
}

vector<string> split (string data)
{
    vector<string> tokens ;
    string curr = "" ;

    for (char c : data)
    {
        if (c == ',')
        {
            tokens.push_back (curr) ;
            curr = "" ;
        }
        else
        {
            curr += c ;
        }
    }

    return tokens ;
}

TreeNode* build(vector<string>& tokens, int& i)
{
    if (tokens[i] == "N")
    {
        i++;
        return NULL;
    }

    TreeNode* root = new TreeNode(stoi(tokens[i]));
    i++;

    root->left = build(tokens, i);
    root->right = build(tokens, i);

    return root;
}

TreeNode* deserialize(string data)
{
    vector<string> tokens = split(data);
    int i = 0;
    return build(tokens, i);
}
};
