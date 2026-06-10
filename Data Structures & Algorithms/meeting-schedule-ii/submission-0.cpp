/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
   int minMeetingRooms (vector<Interval>& intervals)
{
    int n = intervals.size () ;

    vector<int> starts (n) ;
    vector<int> ends (n) ;

    for (int i=0 ; i<n ; i++)
    {
        starts[i] = intervals[i].start ;
        ends[i] = intervals[i].end ;
    }

    sort (starts.begin () , starts.end ()) ;
    sort (ends.begin () , ends.end ()) ;

    int rooms = 0 ;
    int maxRooms = 0 ;

    int i = 0 ;
    int j = 0 ;

    while (i < n)
    {
        if (starts[i] < ends[j])
        {
            rooms++ ;
            maxRooms = max (rooms , maxRooms) ;
            i++ ;
        }
        else
        {
            rooms-- ;
            j++ ;
        }
    }
    return maxRooms ;
}
};
