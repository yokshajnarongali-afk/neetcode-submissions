class Solution {
public:
    void dfs (int row , int col , vector<vector<int>>& grid , vector<vector<int>>& visited , int& Area)
{   
    if ((row < 0 || row >= grid.size ()) || (col < 0 || col >= grid[0].size ()))
    {
        return ;
    }

    if (grid[row][col] == 0)  return ;

    if (visited[row][col] == 1) return ;

    visited[row][col] = 1 ;
    Area++ ;

    dfs (row - 1 , col , grid , visited , Area) ;
    dfs (row + 1 , col , grid , visited , Area) ;
    dfs (row , col - 1 , grid , visited , Area) ;
    dfs (row , col + 1 , grid , visited , Area) ; 
}

int maxAreaOfIsland (vector<vector<int>>& grid)
{
    if (grid.size () == 0) return 0 ;

    int m = grid.size () ;
    int n = grid[0].size () ;
    vector<vector<int>> visited (m , vector<int> (n , 0)) ;
    int res = 0 ;
    for (int i=0 ; i<grid.size () ; i++)
    {
        for (int j=0 ; j<grid[0].size () ; j++)
        {
            if (grid[i][j] != 0 && !visited[i][j])
            {
                int Area = 0 ;
                dfs (i , j , grid , visited , Area) ;
                res = max (res , Area) ;
            }
        }
    }

    return res ;

}
};
