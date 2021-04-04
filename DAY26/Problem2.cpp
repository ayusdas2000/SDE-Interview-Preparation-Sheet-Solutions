/**

Coin Change Problem

Time Complexity - O(S * len(coins))
Space Complexity - O(S)

Explanation:
    We have a collection of infinite coins of different denomination we have to have minimum number of coins which can make the sum of all coin values to target.

Base Case:
    - Incase required sum is 0, we don't need to pick a coin.
    - Incase we get a negative remaining amount we reached an invalid state so return some big garbge value,

Main Logic:
    - Iteratively solve for sub-problem which arised after taking the current coin.
    - Incase we reach some already solved state we return the previously computed result.    

*/
class Solution {
public:
    
    int minCoin(vector<int>& coin,int S,int dp[])
    {
        if(S==0)
            return 0;
        if(S<0)
            return INT_MAX;
        if(dp[S]!=-1)
            return dp[S];
        int mini=INT_MAX;
        for(int i=0;i<coin.size();i++)
        {
            if(coin[i]<=S)
            {
                int res=minCoin(coin,S-coin[i],dp);
                if(res!=INT_MAX and res<mini)
                    mini=res+1;
            }
        }
        
        return dp[S]=mini;
            
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int dp[amount+5];
        memset(dp,-1,sizeof dp);
        int res= minCoin(coins,amount,dp);
        return (res==INT_MAX)?-1:res;
    }
};
