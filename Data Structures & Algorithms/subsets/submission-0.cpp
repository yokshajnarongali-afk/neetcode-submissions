class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size () ;
    vector<vector<int>> help = {{}}; 

    for (int i=0 ; i<n ; i++)
    {
        int size = help.size () ;
        for (int j=0 ; j<size ; j++)
        {
            vector<int> temp = help[j] ;
            temp.push_back (nums[i]) ;
            help.push_back (temp) ;
        }
    }
    return help ;
    }
};
