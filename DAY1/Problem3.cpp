/* Repeat and Missing Number */

class Solution {
public:
    void getTwoElements(vector<int>& nums) 
    {   
        int n = nums.size();

	/* Xor variable will have xor of all the in
	the array and numbers from 1 to n and setbit
	will have only single set bit of Xor */
	int Xor=0,setbit;

	int x=0,y=0;

	/* To get xor of all array elements */ 
	for(int i=0;i<n;i++)
	   Xor^=nums[i];

	/* To get xor of numbers from 1 to n */ 
	for(int i=1;i<=n;i++)
	   Xor^=i;

	/* To get rightmost set bit */
	setbit=Xor & ~(Xor-1);

	/* Dividing elements into two sets using the 
	set bit and to get xor of the sets */
	for(int i=0;i<n;i++)
	{
	   if(nums[i]&setbit)
	      x^=nums[i];  //set1
	   else
	      y^=nums[i];  //set2
	}
	for(int i=1;i<=n;i++)
	{
	   if(i&setbit)
	      x^=i;        //set1
	   else
	      y^=i;        //set2
	}
	cout<<"Missing number : "<<x<<endl;
	cout<<"Repeatinng number : "<<y;
    }
};