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
        if (nums[i] > target)   continue ;

        path.push_back (nums[i]) ;
        solve (i , target - nums[i] , nums , path , res) ;
        path.pop_back () ;
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int target)
{
    vector<vector<int>> res ;
    vector<int> path ;

    solve (0 , target , nums , path , res) ;

    return res ;
}
};
