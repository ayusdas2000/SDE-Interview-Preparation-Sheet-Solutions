/* Sort an array of 0’s 1’s 2’s without using extra space or sorting algo */

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int low,mid,high;
        low=0;
        mid=0;
        high=nums.size()-1;
	
	/* Iterate all the elements */
        while(mid<=high)
        {
	    /* If element is 0 */
            if(nums[mid]==0)
            {
		/* Swap the elements */
                swap(nums[low],nums[mid]);   
                low++;
                mid++;
            }

	    /* If element is 1 */
            else if(nums[mid]==1)
            {
                mid++;
            }

	    /* If element is 2 */
            else
            {
		/* Swap the elements */
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};
