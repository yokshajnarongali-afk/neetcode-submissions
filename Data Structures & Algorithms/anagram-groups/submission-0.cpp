class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<int>> freq (strs.size () , vector<int> (26 , 0)) ;
    map <vector<int> , vector<string>> m ;
    vector<vector<string>> res ;

    for (int i=0 ; i<strs.size () ; i++)
    {
        for (int j=0 ; j<strs[i].length () ; j++)
        {
            freq[i][strs[i][j] - 'a']++ ;
        }

        m[freq[i]].push_back (strs[i]) ;
    }
    
    for (auto& it : m)
    {
        res.push_back (it.second) ;
    }

    return res ;
    }
};
