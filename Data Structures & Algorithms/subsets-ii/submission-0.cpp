class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            int n = nums.size () ;
    sort (nums.begin () , nums.end ()) ;
    vector<vector<int>> help = {{}}; 

    int start = 0 , end = 0 ;

    for (int i=0 ; i<n ; i++)
    {
        start = 0 ;
        if (i > 0 && nums[i] == nums[i-1]) 
        {
            start = end ;
        }
        end = help.size () ;
        for (int j=start ; j<end ; j++)
        {
            vector<int> temp = help[j] ;
            temp.push_back (nums[i]) ;
            help.push_back (temp) ;
        }
    }
    return help ;
    }
};
