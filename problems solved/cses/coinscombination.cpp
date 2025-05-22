##include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int comb(int m,vector<int> &coins,vector<int> &dp){
    if(m<0) return 0;
    if(dp[m]!=-1)return dp[m];
    dp[m]=0;
    for(auto i : coins){
        dp[m]+=comb(m - i,coins,dp)%mod;
    }
    return dp[m];
}
 
void test_case(){
    int n,x; cin >> n >> x;
    vector<int> coins(n),dp(x+1,-1);
    dp[0]=1;
    for(int i=0;i<n;i++)cin >> coins[i];
    cout << comb(x,coins,dp)%mod << endl;
}
 
int32_t main(){
    test_case();
}

