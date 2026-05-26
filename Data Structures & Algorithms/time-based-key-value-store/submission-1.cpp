class TimeMap {
public:
        unordered_map<string , vector<pair<int , string>>> m ;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
               m[key].push_back ({timestamp , value}) ;

    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end ()) return "" ;

        vector<pair<int , string>>& v = m[key] ;
        int l = 0 , r = v.size ()-1 ;
        string res = "" ;

        while (l <= r)
        {
            int mid = l + (r-l)/2 ;

            if (v[mid].first == timestamp)
            {
                return v[mid].second ;
            }
            else if (v[mid].first < timestamp)
            {
                res = v[mid].second ;
                l = mid+1 ;
            }
            else 
            {
                r = mid-1 ;
            }
        }

        return res ;
    }
};
