class Solution {
public:
double power(double x, long long n)
{
    if (n == 0)
        return 1;

    double res = power(x, n / 2);

    if (n % 2 == 0)
        return res * res;

    return res * res * x;
}

double myPow(double x, int n)
{
    long long y = n;

    if (y < 0)
    {
        x = 1 / x;
        y = -y;
    }

    return power(x, y);
}
};
