/* Pascal Triangle */

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> pascal(numRows);
        for(int i=0;i<numRows;i++)
        {
	    /* resize the row which will contains number
	    of elements equal to the row number */
            pascal[i].resize(i+1);

	    /* first and last element of each row is one */
            pascal[i][0]=1;
            pascal[i][i]=1;

	    /* compute other elements of that row */
            for(int j=1;j<i;j++)
            {
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
        return pascal;
    }
};