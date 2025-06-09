#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int n,C;
vector<int> players;

int pick(int i,int c,vector<vector<int>> &dp){
    if(c>=C) return 1;
    if(i==n-1) return 0;
    if(dp[i][c]!=-1) return dp[i][c];

    int take=0;
    if(c>=players[i]) take=pick(i+1,c+players[i],dp)%mod;
    int nottake=pick(i+1,c,dp)%mod;
    
    return dp[i][c]=(take+nottake)%mod;
}


void test_case(){
    cin >> n >> C;
    players.resize(n-1);
    int maxi=INT_MIN;
    int p1; cin >> p1;
    for(int i=0;i<n-1;i++){cin >> players[i];maxi=max(maxi,players[i]);}
    vector<vector<int>> dp(n,vector<int>(C+maxi+1,-1));
    sort(players.begin(),players.end());
    //for(auto i : players) cout << i << " ";
    //cout << endl;
    cout << pick(0,p1,dp)%mod <<endl;
    //for(int i=0;i<n;i++){for(int j=0;j<C+maxi+1;j++){cout << dp[i][j] << " ";}cout << endl;}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	test_case();
}

