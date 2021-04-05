/**
Subset Sum Problem

Time Complexity - O(N*SUM)
Space Complexity - O(N*SUM)

Explanation:
Base Case:
- Since we are decrementing the remaining sum amount in each state we have to keep a check upon the sign of 'rem', incase we hit a negative value of rem we return 0(indicating false)
- More over in any case if we have scanned the entire array and try to move to some out of bound position then also return 0
- Incase we reach a state where remaining sum is 0 we return a positive value i.e. 1(indicating true) 

Main Logic:
- At each step we have either of the two choices:
    - Leave the current element and solve the sub-problem for remaining sum from next index; or,
    - Take the current element reduce the remaining sum by the value of currently taken element and keeping solving the remaining sub-problems from the next index.
    
*/
class Solution {
public:
    int solve(int idx,int rem,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(rem<0 or idx>=nums.size())
        {
            return 0;
        }
        if(rem==0)
        {
            return 1;
        }
        
        int &ans = dp[idx][rem];
        if(ans!=-1)
            return ans;
        
        ans = solve(idx+1,rem-nums[idx],nums,dp)||solve(idx+1,rem,nums,dp);
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        if(sum&1) // sum is odd - so can't be divided by 2 
            return 0;
        vector<vector<int>> dp(nums.size()+5,vector<int>(sum/2 + 5,-1));
        return solve(0,sum/2,nums,dp);
    }
};