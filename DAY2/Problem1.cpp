/* Set Matrix Zeros */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool f=true;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
	    /* check if there is zero in first column */
            if(matrix[i][0]==0)
                f=false;

	    /* check if there is zero except the first column */
            for(int j=1;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
		    /* change the value the corresponding elements 
		    of the first row and first column to zero */
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=1;j--)
            {
		/* change the value of the element to zero if either 
		of the corresponding element of first row and first
		column is zero */
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
	    /* change the value of element of first column to zero 
	    if flag value is false */
            if(f==false)
                matrix[i][0]=0;
        }
    }
};