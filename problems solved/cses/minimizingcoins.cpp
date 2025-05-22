##include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int INF = LLONG_MAX/2+1;
 
int32_t main(){
	int n,x; cin >> n >> x;
	vector<int> coins(n),dp;
	for(int i=0;i<n;i++)cin>>coins[i];
	dp.assign(x+1,INF);
	dp[0]=0;
	for(int j=1;j<=x;j++){
		for(int c : coins){
			if(j-c>=0){
				dp[j]=min(dp[j],dp[j-c]+1);		
			}	
		}
	}
	cout << ((dp[x]==INF)?-1:dp[x]) << endl;
}
