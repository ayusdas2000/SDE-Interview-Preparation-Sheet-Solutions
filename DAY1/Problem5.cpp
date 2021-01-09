/* Kadane’s Algorithm */

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
	/* store first element in maximum */
        int sum=0,Max=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

	    /* check whether current sum is greater then maximun */
            Max=max(sum,Max);

	    /* check whether current sum is less than zero */
            if(sum<0)
                sum=0;
        }
        return Max;
    }
};