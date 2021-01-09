/* Merge two sorted Arrays without extra space */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        if(n!=0)
        {
            for(int i=0;i<m;i++)
            {
		
		/* check whether the current element of first array is
		less the first element of second array */
                if(nums1[i]>nums2[0])
                {
		    /* swap the current element of first array is
		    less the first element of second array */
                    swap(nums1[i],nums2[0]);

                    for(int j=0;j<n-1;j++)
                    {
			/* find the right position of the first element of
			second array to make it sorted */
                        if(nums2[j]>nums2[j+1])
                        {
                            swap(nums2[j],nums2[j+1]);
                        }
                        else
                            break;
                    }
                }

            }
            int x=0;
	    /* store the elements of second array in the first array */
            for(int i=m;i<m+n;i++)
                nums1[i]=nums2[x++];
        }
    }
};