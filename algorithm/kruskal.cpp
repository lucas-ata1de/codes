#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> parent,sz;
int find_set(int x){
	if(parent[x]==x) return x;
	return parent[x]=find_set(parent[x]);
}

void union_set(int x,int y){
	int a=find_set(x);
	int b=find_set(y);
	if(a==b) return; 
	if(sz[a]<sz[b]) swap(a,b);
	parent[b]=a;
	sz[a]+=b;
}

void test_case(){
	int n,m; cin >> n>> m;
	parent.resize(n);sz.resize(n);
	vector<tuple<int,int,int>> mst; 
	//makeset
	for(int i=0;i<n;i++){
		parent[i]=i;
		sz[i]=1;
	}
	for(int i=0;i<m;i++){
		int a,b,w; cin >> a >> b >> w;
		tuple<int,int,int> t(w,a,b);
		mst.push_back(t);
	}
	sort(mst.begin(),mst.end());
	for(int i=1;i<m;i++){
		if(find_set(get<1>(mst[i])) != find_set(get<2>(mst[i]))){
			union_set(get<1>(mst[i]),get<2>(mst[i]));
		}
	}

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	test_case();
}

