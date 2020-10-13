#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

vector<int> adj[N];
int par[N];
int child[N];
bool vis[N];

void dfs(int node){
	//child[node]=1;
	vis[node]=1;
	for(int x:adj[node]){
		if(!vis[x]){
			child[node]+=1;
			par[x]=node;
			dfs(x);
		}
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			par[i]=0;
			dfs(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(par[i]!=0){
			if(child[par[i]]<child[i]){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}