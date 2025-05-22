class Solution {
public:
    int avance(string &s,vector<vector<int>> &dp,int i,int j){
        if(i>j) return 0;
        if(i==j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            dp[i][j]= 2 + avance(s,dp,i+1,j-1);
        }else{
            dp[i][j]= max(avance(s,dp,i,j-1),avance(s,dp,i+1,j));
        }
        return dp[i][j];

    }
    int longestPalindromeSubseq(string s) {
       vector<vector<int>>  dp(s.size(),vector<int>(s.size()+1,-1));
       return avance(s,dp,0,s.size()-1);
    }

};
