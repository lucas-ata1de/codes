#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
	int n;cin>>n;
	vector<int> v(n),prefix(n+1);
	cin >> v[0]; 
	for(int i=1;i<=n;i++){
		if(i<n)cin >> v[i];
		prefix[i]=v[i-1]+prefix[i-1];
	}
	for(auto i : prefix) cout << i << endl;
	//prefix sum
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	test_case();
}

