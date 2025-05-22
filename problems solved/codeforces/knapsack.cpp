#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF -30000
#define 0 0LL

int store(int c,set<pair<int,int>> items,vector<int> &dp){
    cout << c << endl;
    //casos base
    if(c==0) return 0;
    if(c<0) return INF;
    if(dp[c]!=-1) return dp[c];

    //brute+memo
    dp[c]=0;
    for(int i=0;i<items.size();i++){
        dp[c]+=max(0,item.second + store(c-item.first,items,dp));
    }
    return dp[c];
}

void test_case(){
    int s,n; cin >> s >> n;
    set<pair<int,int>> items;
    for(int i=0;i<n;i++){
        pair<int,int> p; cin >> p.first >> p.second;
        items.insert(p);
    }
    ;
    vector<int> dp(s+1,-1);
    cout << store(s,items,dp) << endl;
    
}

int32_t main(){
    test_case();

}

