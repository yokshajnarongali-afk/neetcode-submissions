class Solution {
public:
void solve (int row , int n , vector<string>& board , vector<vector<string>>& res , vector<int>& col , vector<int>& diag1 , vector<int>& diag2)
{
    if (row == n)
    {
        res.push_back (board) ;
        return ;
    }

    for (int i=0 ; i<n ; i++)
    {
        if (col[i] || diag1[row - i + n - 1] || diag2[row + i])
        {
            continue ;
        }

        board[row][i] = 'Q' ;

        col[i] = 1 ; diag1[row - i + n - 1] = 1 ; diag2[row + i] = 1 ;

        solve (row + 1 , n , board , res , col , diag1 , diag2) ;

        board[row][i] = '.' ;

        col[i] = 0 ; diag1[row - i + n - 1] = 0 ; diag2[row + i] = 0 ;
    }
}

vector<vector<string>> solveNQueens (int n)
{
    vector<vector<string>> res ;

    vector<string> board (n , string (n , '.')) ;

    vector<int> col (n , 0) ; vector<int> diag1 (2 * n - 1 , 0) ; vector<int> diag2 (2 * n - 1 , 0) ;

    solve (0 , n , board , res , col , diag1 , diag2) ;

    return res ;

}

};
