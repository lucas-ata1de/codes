#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v){
	visited[v]=true;
	for(auto u : adj[v]){
		if(visited[u])continue;
		dfs(u);
	}
	return;
}

void test_case(){
	int v,e; cin >> v >> e;
	adj.resize(v,vector<int>()); visited.resize(v);
	for(int i=0;i<e;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		// non-directed case: adj[b].push_back(a);
	}
	for(int i=0;i<v;i++){
		if(visited[i])continue;
		dfs(i);
	}

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	test_case();
}

