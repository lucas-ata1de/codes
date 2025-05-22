
// User function Template for C++


class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int> dp(n+1);
        for(auto &i : dp) i=-1;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]=max(dp[i],price[j-1]+dp[i-j]);
            }
        }
        return dp[n];
        
    }
};
