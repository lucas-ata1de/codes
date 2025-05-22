#/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <bits/stdc++.h>
using namespace std;
#define inf INT_MIN/2;
 
int n;
vector<int> price,pages;
 
int pick(int i,int m,vector<vector<int>> &dp){
    if(m<0){
        return inf;
    }
    if(i==n){
        return 0;
    }
    if(m==0){
        return dp[i][m]=0;
    }
    if(dp[i][m]!=-1){
        return dp[i][m];
    }
    
    int take= pick(i + 1,m - price[i],dp) + pages[i];
    int nottake = pick(i + 1,m,dp);
    return dp[i][m]=max(take,nottake);
}
 
int main(){
    int m; cin >> n >> m;
    price.resize(n); pages.resize(n);
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    for(int i=0;i<n;i++){
        cin >> pages[i];
    }
    vector<vector<int>> dp(m+1,vector<int>(n,0));
    for(int i=1;i<=m;i++) if(i-price[n-1]>=0) dp[i][n-1]=pages[n-1];
    
    for(int j=1;j<=m;j++){
        for(int i=n-2;i>=0;i--){
            if(j-price[i]<0){
                dp[j][i]=max(0,dp[j][i+1]);
                continue;
            }
            dp[j][i]=max(dp[j][i+1],pages[i]+dp[j-price[i]][i+1]);
        }
    }
    cout << dp[m][0] <<endl;
    
    
    return 0;
}
