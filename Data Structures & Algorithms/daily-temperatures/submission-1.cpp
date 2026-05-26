class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         int n = temperatures.size () ;
    stack<int> s ;
    vector<int> res(n , 0) ;

    for (int i=0; i<n ; i++)
    {
        while (!s.empty () && temperatures[i] > temperatures[s.top ()])
        {
            int prev = s.top () ;
            s.pop () ;
            res[prev] = i - prev ;
        }
        s.push (i) ;
    }

    return res ;
    }
};
