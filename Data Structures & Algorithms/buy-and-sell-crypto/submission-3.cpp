class Solution {
public:
    int maxProfit(vector<int>& p) {
         int n = p.size () ;
    int bb = p[0] , maxP = 0 ;
    for (int i=1 ; i<n ; i++)
    {

            maxP = max (maxP , (p[i] - bb)) ;
        
        bb = min (bb , p[i]) ;
    }

    return maxP ;}
};
