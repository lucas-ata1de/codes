int sub(int i, int j, vector<vector<int>>& dp, string& text1, string& text2) {
    if (i == -1 or j == -1) {
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if (text1[i] == text2[j]) {
        return dp[i][j] = 1 + sub(i - 1, j - 1, dp, text1, text2);
    }
    return dp[i][j] = max(sub(i - 1, j, dp, text1, text2),sub(i, j - 1, dp, text1, text2));
}
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return sub(text1.size() - 1, text2.size() - 1, dp, text1, text2);
    }
};
