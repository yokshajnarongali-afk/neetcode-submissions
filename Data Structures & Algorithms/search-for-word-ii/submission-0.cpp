class Solution {
public:
    struct Node
{
    Node* links[26] ;

    string word = "" ;

    Node ()
    {
        for (int i=0 ; i<26 ; i++)
        {
            links[i] = NULL ;
        }
    }
} ;

Node* root = new Node () ;

void insert (string word)
{
    Node* node = root ;

    for (char ch : word)
    {
        if (node -> links[ch - 'a'] == NULL)
        {
            node -> links[ch - 'a'] = new Node () ;
        }
        node = node -> links[ch - 'a'] ;
    }

    node -> word = word ;
}

void dfs (int i , int j , vector<vector<char>>& board , Node* node , vector<string>& ans)
{
    int m = board.size () ;
    int n = board[0].size () ;

    if (i < 0 || j < 0 || i >= m || j >= n)
    {
        return ;
    }

    char ch = board[i][j] ;

    if (ch == '#')
    {
        return ;
    }

    if (node -> links[ch - 'a'] == NULL)
    {
        return ;
    }

    node = node -> links[ch - 'a'] ;

    if (node -> word != "")
    {
        ans.push_back (node -> word) ;
        node -> word = "" ;
    }

    board[i][j] = '#' ;

    dfs (i + 1 , j , board , node , ans) ;
    dfs (i - 1 , j , board , node , ans) ;
    dfs (i , j + 1 , board , node , ans) ;
    dfs (i , j - 1 , board , node , ans) ;

    board[i][j] = ch ;
}

vector<string> findWords (vector<vector<char>>& board , vector<string>& words)
{
    for (string word : words)
    {
        insert (word) ;
    }

    vector<string> ans ;

    int m = board.size () ;
    int n = board[0].size () ;

    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            dfs (i , j , board , root , ans) ;
        }
    }

    return ans ;
}
};
