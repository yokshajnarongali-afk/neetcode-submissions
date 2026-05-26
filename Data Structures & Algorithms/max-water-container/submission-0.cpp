class Solution {
public:
    int maxArea(vector<int>& h) {
         int n = h.size () ;
    int s = 0 , e = n-1 ;
    int maxA = INT_MIN ;
    while (s < e)
    {
        int area = (min(h[s],h[e]) * (e-s)) ;
        maxA = max (maxA , area) ;

        if (h[s] < h[e]) s++ ;
        else e-- ;
    }

    return maxA ;
    }
};
