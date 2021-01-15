/* Next Permutation */

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
	/* return the array if size equals to one */
        if(nums.size()==1)
            return;

        int n=nums.size(),f=0,i,j;

	/* find first break point */
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
	    /* if there is no break point, reverse the array */
            if(i==0)
            {
                reverse(nums.begin(),nums.end());
                f=1;
            }
        }
        if(f!=1)
        {
	    /* find second break point */
            for(j=n-1;j>i;j--)
            {
                if(nums[j]>nums[i])
                    break;
            }

	/* swap the element of first break point 
	with second break point */
        swap(nums[j],nums[i]);

	/* reverse the array from first break point
	to end of the array */
        reverse(nums.begin()+i+1,nums.end());

        }
    }
};