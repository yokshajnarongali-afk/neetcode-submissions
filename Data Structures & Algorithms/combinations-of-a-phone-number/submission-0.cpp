class Solution {
public:
void solve (vector<string>& res , vector<string>& mapping , int index , string path , string digits)
{
    if (digits.length () == 0)  return ;

    if ( index == digits.length ())    
    {
        res.push_back (path) ;
        return ;
    }

    string letters = mapping[digits[index] - '0'] ;

    for (char ch : letters)
    {
        path.push_back (ch) ;
        solve (res , mapping , index + 1 , path , digits) ;
        path.pop_back () ;
    }


}

vector<string> letterCombinations (string digits)
{
    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> res ;
    string path ;

    solve (res , mapping , 0 , path , digits) ;

    return res ;

}
};
