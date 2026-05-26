class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int> s (nums.begin () , nums.end ()) ;
    int res = 0 ;

    for (int i=0 ; i<nums.size () ; i++)
    {
        if (s.find (nums[i] - 1) == s.end ())
        {
            int curr = nums[i] ;
            int length = 1 ;

            while (s.find (curr + 1) != s.end ())
            {
                curr++ ;
                length++ ;
            }

            res = max (res , length) ;
        }
    }

    return res ;
    }
};
