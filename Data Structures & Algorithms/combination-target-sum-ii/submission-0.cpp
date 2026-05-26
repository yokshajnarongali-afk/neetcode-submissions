class Solution {
public:
void solve(int index, int target, vector<int>& nums,vector<int>& path, vector<vector<int>>& res)
{
    if (target == 0)
    {
        res.push_back (path) ;
        return  ;
    }

    for (int i=index ; i<nums.size () ; i++)
    {
        if (i > index && nums[i] == nums[i-1])  continue ;

        if (nums[i] > target)   continue ;

        path.push_back (nums[i]) ;
        solve (i+1 , target - nums[i] , nums , path , res) ;
        path.pop_back () ;
    }
}

vector<vector<int>> combinationSum2(vector<int>& nums, int target)
{
    vector<vector<int>> res ;
    vector<int> path ;

    sort (nums.begin () , nums.end ()) ;

    solve (0 , target , nums , path , res) ;

    return res ;
}
};
