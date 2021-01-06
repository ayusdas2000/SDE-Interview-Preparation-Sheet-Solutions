/* Find the duplicate in an array of N integers. */

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
	/* x is a fastpointer which take 2 steps
	and y is a slowpointer which take 1 step. */
        int x,y;

        x=nums[0];
        y=nums[0];

	/* Iterate till x not equals to y */
        do
        {
            x=nums[x];
            y=nums[y];
            y=nums[y];
        }while(x!=y);

	/* Bring the fastpointer to initial position */
        x=nums[0];

	/* Iterate till x not equals to y */
        while(x!=y)
        {
            x=nums[x];
            y=nums[y];
        }

	/* X have the duplicate value */
        return x;
    }
};