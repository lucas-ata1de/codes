#include<bits/stdc++.h>
using namespace std;
#define int long long


void test_case(){
	int v,e; cin >> v >> e;
	vector<vector<int>> adj(v,vector<int>());
	vector<bool> visited(v);
	//reading
	for(int i=0;i<e;i++){
		int a,b; cin >> a >> b;
		//careful vertex 1-indexed:
		//a--; b--;
		adj[a].push_back(b);
		// non-directed case: adj[b].push_back(a);
	}
	//algorithm
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		visited[q.front()]=true;
		for(auto i : adj[q.front()]){
			if(visited[i])continue;
			q.push(i);
		}
		cout << q.front() << endl;
		q.pop();
	}
	//bfs
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	test_case();
}

