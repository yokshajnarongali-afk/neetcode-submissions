class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int n = s.length () , st = 0 , left = 0 ;
    int maxL = 0 , l = 0 ;
    unordered_set<char> set ;
    while (st < n)
    {
        if (set.find (s[st]) == set.end ())
        {
            set.insert (s[st]) ;
            maxL = max (maxL , st-left+1) ;
            st++ ;
        }
        else
        {
            set.erase (s[left]) ;
            left++ ;
        }
    }
    return maxL ;
    }
};
