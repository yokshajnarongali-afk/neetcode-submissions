class Solution {
public:
void solve (int open , int close , int n , string path , vector<string>& res)
{
    if (path.size () == 2 * n)
    {
        res.push_back (path) ;
        return ;
    }

    if (open < n)   solve (open + 1 , close , n , path + '(', res) ;

    if (close < open)   solve (open , close + 1 , n , path + ')', res) ;
}

vector<string> generateParenthesis (int n)
{
    vector<string> res ;

    solve (0 , 0 , n , "" , res) ;

    return res ;
}
};
