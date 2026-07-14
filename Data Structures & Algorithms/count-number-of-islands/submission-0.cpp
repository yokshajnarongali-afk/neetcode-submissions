class Solution {
public:
    void dfs (int row , int col , vector<vector<char>>& grid , vector<vector<int>>& visited)
{   
    if ((row < 0 || row >= grid.size ()) || (col < 0 || col >= grid[0].size ()))
    {
        return ;
    }

    if (grid[row][col] == '0')  return ;

    if (visited[row][col] == 1) return ;

    visited[row][col] = 1 ;

    dfs (row - 1 , col , grid , visited) ;
    dfs (row + 1 , col , grid , visited) ;
    dfs (row , col - 1 , grid , visited) ;
    dfs (row , col + 1 , grid , visited) ; 
}

int numIslands (vector<vector<char>>& grid)
{
    if (grid.size () == 0) return 0 ;

    int m = grid.size () ;
    int n = grid[0].size () ;
    vector<vector<int>> visited (m , vector<int> (n , 0)) ;
    int island = 0 ;
    for (int i=0 ; i<grid.size () ; i++)
    {
        for (int j=0 ; j<grid[0].size () ; j++)
        {
            if (grid[i][j] != '0' && !visited[i][j])
            {
                island++ ;
                dfs (i , j , grid , visited) ;
            }
        }
    }

    return island ;

}
};
