class Solution {
public:

int nextNum (int n)
{
    int sum = 0 ;
    while (n > 0)
    {
        int r = n % 10 ;
        sum += (r * r) ;
        n /= 10 ;
    }

    return sum ;
}

bool isHappy (int n)
{
    int slow = n ;
    int fast = nextNum (n) ;

    while (fast != 1 && slow != fast)
    {
        slow = nextNum (slow) ;
        fast = nextNum (nextNum (fast)) ;
    }
    return fast == 1 ;
}
};
