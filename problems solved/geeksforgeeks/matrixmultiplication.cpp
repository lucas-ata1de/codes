#define INF INT_MAX

int multi(int i,int j,vector<vector<int>> &dp,vector<int> &arr){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    dp[i][j]=INF;
    for(int k=i;k<=j-1;k++){
        dp[i][j] = 
        min(dp[i][j],multi(i , k , dp , arr) + multi(k + 1 ,j,dp,arr)+ arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j];
}

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
        return multi(1,arr.size()-1,dp,arr);
    }
}
