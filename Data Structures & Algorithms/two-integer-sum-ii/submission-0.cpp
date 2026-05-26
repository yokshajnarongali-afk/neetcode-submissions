class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int s = 0 , e = n.size ()-1 ;

        while (s <= e)
        {
            int sum = n[s] + n[e] ;
            if (sum == t)
            {
                return {s + 1 , e + 1} ;
            }
            else if (sum < t)
            {
                s++ ; continue ;
            }
            else
            {
                e-- ; continue ;
            }
        }
        return {};
    }

} ;
