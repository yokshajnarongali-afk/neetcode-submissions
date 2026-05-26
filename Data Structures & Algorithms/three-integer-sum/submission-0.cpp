class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
            sort (n.begin () , n.end()) ;
    vector<vector<int>> ans ;
    for (int i=0 ; i<n.size () ; i++)
    {
        if (i>0 && n[i] == n[i-1]) continue ;
        int a = n[i] ;
        int s = i+1 , e = n.size ()-1 ;
        while (s < e)
        {
            int sum = n[s]+n[e]+a ;
            if (sum == 0) 
            {
                ans.push_back ({a , n[s] , n[e]}) ;
                s++ ; e-- ;
                while (s<e && n[s] == n[s-1]) s++ ;
            } 
            else if (sum < 0) s++ ;
            else e-- ;
        }
    }

    return ans ;
    }
};
