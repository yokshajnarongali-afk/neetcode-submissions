class Solution {
public:
    bool isValid (char c)
    {
        if ((c >= '0' && c <= '9') || tolower (c) >= 'a' && tolower (c) <= 'z')
        {
            return true ;
        }
        return false ;
    }
    bool isPalindrome(string str) 
    {
        int s = 0 , e = str.length ()-1 ;
    
        while (s <= e)
        {
            if (!isValid (str[s]))  {s++ ; continue ;}
            if (!isValid (str[e]))  { e-- ; continue ;}

            if (tolower(str[(s)]) != tolower(str[e]))
            {
                return false ;
            }
            s++ ; e-- ;
        }
        return true ;
    }
};
