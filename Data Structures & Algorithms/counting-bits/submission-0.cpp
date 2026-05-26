class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans (n+1 , 0);

    for (int i=0 ; i<=n ; i++)
    {
        int temp = 0 ;
        int num = i ;
        while (num > 0)
        {
            if ((num & 1) == 1)
            temp++ ;

            num >>= 1 ;
        }
        ans[i] = temp ;
    }

    return ans ;
    }
};
