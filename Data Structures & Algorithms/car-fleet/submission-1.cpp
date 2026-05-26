class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size () ;
    stack<double> s ;
    vector<pair<int , double>> cars ;

    for (int i=0 ; i<n ; i++)
    {
        double t = (double) (target-position[i])/speed[i] ;
        cars.push_back ({position[i] , t}) ;
    }

    sort (cars.begin () , cars.end () , greater<> ()) ;

    int f = 0 ;
    double last = 0 ;
    for (int i=0 ; i<n ; i++)
    {
        double t = cars[i].second ;
        if (t > last)
        {
            f++ ;
            last = t ;
        }
    }

    return f ;
    }
};
