class Solution {
public:
bool isPalin (string s , int l , int r)
{
    while (l < r)
    {
        if (s[l] != s[r])   return false ;
        
        l++ ; r-- ;
    }
    
    return true ;
}

void solve (int index , string& s , vector<string>& path , vector<vector<string>>& res )
{
    if (index == s.length ())
    {
        res.push_back (path) ;
        return ;
    }

    for (int i=index ; i<s.length () ; i++)
    {
        if (isPalin (s , index , i))
        {
            path.push_back (s.substr (index , i - index + 1)) ;

            solve (i + 1 , s , path , res) ;

            path.pop_back () ;
        }
    }
}

vector<vector<string>> partition (string s)
{
    vector<vector<string>> res ;
    vector<string> path ;

    solve (0 , s , path , res) ;

    return res ;
}
};
