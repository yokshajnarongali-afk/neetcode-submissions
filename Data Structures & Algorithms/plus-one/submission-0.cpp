class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            vector<int> res ;
    int temp = 1 ;
    for (int i=digits.size ()-1 ; i>=0 ; i--)
    {
        int temp2 = digits[i] + (temp%10) ;
        digits[i] = temp2 % 10 ;
        temp2 /= 10 ;
        temp = temp2 ;
    }

    while (temp > 0)
    {
        res.push_back (temp%10) ;
        temp /= 10 ;
    }
    for (int i=0 ; i<digits.size () ; i++)
    {
        res.push_back (digits[i]) ;
    }

    return res ;
    }
};
