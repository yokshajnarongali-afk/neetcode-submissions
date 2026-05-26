class MinStack 
{
    public :

    stack<pair<int,int>> s ;
   

    MinStack () {}
    
    void push (int val)
    {
        int mVal ;
        if (s.empty ())
        {
            mVal = val ;
        }
        else
        {
            mVal = min (val , s.top().second) ;
        }
        s.push ({val , mVal}) ;
    }

    void pop ()
    {
        if (!s.empty ())
        {
            s.pop () ;
        }
    }

    int top ()
    {
        return s.top ().first ;
    }

    int getMin ()
    {
        return s.top ().second ;
    }
} ;