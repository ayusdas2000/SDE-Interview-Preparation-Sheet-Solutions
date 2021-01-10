/* Merge Overlapping Subintervals */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
	/* sort intervals in increasing order */
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> v1;
        vector<int> v2,v3;
        v2=intervals[0];

        for(int i=0;i<intervals.size();i++)
        {
            v3=intervals[i];

	    /* check whether the intervals are overlapping */
            if(v3[0]<=v2[1])
            {
		/* merge previous and current intervals */
                v2[1]=max(v2[1],v3[1]);
            }
            else
            {
		/* store it if the interval is not overlapping */
                v1.push_back(v2);

                v2=v3;
            }
        }
        v1.push_back(v2);
        return v1;
    }
};