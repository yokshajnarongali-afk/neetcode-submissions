class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int , int> m ;
    vector<int> res ;

    for (int i=0 ; i<nums.size () ; i++)
    {
        m[nums[i]]++ ;
    }

    vector<vector<int>> bucket (nums.size () + 1) ;

    for (auto it : m)
    {
        bucket[it.second].push_back (it.first) ;
    }

    for (int i = bucket.size () - 1 ; i >= 0 ; i--)
    {
        for (int j=0 ; j<bucket[i].size () ; j++)
        {
            res.push_back (bucket[i][j]) ;

            if (res.size () == k)
            {
                return res ;
            }
        }
    }
    }
};
