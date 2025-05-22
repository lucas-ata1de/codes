#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i]; 
	}
	int max_current=0,max_global=0;
	for(int i=0;i<n;i++){
		max_current=max(v[i],max_current+v[i]);
		max_global=max(max_global,max_current);
	}
	//kanades

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	test_case();
}

