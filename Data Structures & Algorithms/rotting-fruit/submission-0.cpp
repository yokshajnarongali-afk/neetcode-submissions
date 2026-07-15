class Solution {
public:
    int orangesRotting (vector<vector<int>>& grid)
{
    int time = 0 ;
    queue<pair<int , int>> q ;
    int fresh = 0 ;

    for (int i=0 ; i<grid.size () ; i++)
    {
        for (int j=0 ; j<grid[0].size () ; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push ({i , j}) ;
            }
            if (grid[i][j] == 1)
            {
                fresh++ ;
            }
        }
    }

    if (fresh == 0) return time ;

    int dr[4] = {-1 , 1 , 0 , 0} ;
    int dc[4] = {0 , 0 , -1 , 1} ;
    while (!q.empty ())
    {
        int size = q.size () ;

        for (int i=0 ; i<size ; i++)
        {
            int row = q.front ().first ;
            int col = q.front ().second ;
            q.pop () ;

            for (int j=0 ; j<4 ; j++)
            {
                int newRow = row + dr[j] ;
                int newCol = col + dc[j] ;

                if (newRow < 0 || newCol < 0 || newRow >= grid.size () || newCol >= grid[0].size ())  continue ;

                if (grid[newRow][newCol] == 1)
                {
                    grid[newRow][newCol] = 2 ;
                    fresh-- ;
                    q.push ({newRow , newCol}) ;
                }
            }
        }

        if (!q.empty ())    time++ ;
    }

    if (fresh > 0)  return -1 ;
    else    return time ;
}
};
