#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAX 1000005
#define mod (int)(1e8)
#define sp fixed<<setprecision(12)

const int N=10005;

vector<int> graph[N];
bool vis[N];
int dis[N];

void bfs(int src){
    queue<int> q;
    dis[src]=0;
    q.push(src);
	vis[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto x:graph[node]){
            if(!vis[x]){
				vis[x]=1;
                dis[x]=dis[node]+6;
                q.push(x);
            }
        }
    }
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;

    int t=1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            graph[i].clear();
            vis[i]=false;
            dis[i]=-1;
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        int ss;
        cin>>ss;

        bfs(ss);

        for(int i=1;i<=n;i++){
            if(i!=ss){
                cout<<dis[i]<<' ';
            }
        }
        cout<<'\n';
    }

    return 0;
    
}