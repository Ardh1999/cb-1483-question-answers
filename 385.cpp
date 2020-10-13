#include <bits/stdc++.h>
#define int long long int
#define pb push_back

#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;

vector<int> graph[51];

int bfs(int src,int n){
    queue<int> q;
    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto x:graph[node]){
            if(dist[x]==INT_MAX){
                q.push(x);
                dist[x]=dist[node]+1;
            }
        }
    }
    return dist[n];
}


void solve(){
    int n,l,s;
    cin>>n>>l>>s;
    for(int i=1;i<=n;i++){
        graph[i].clear();
    }
    vector<int> board(n+1,0);
    while(l--){
        int x,y;
        cin>>x>>y;
        board[x]=(y-x);
    }
    while(s--){
        int x,y;
        cin>>x>>y;
        board[x]=(x-y);
    }
    for(int i=1;i<n;i++){
        for(int dice=1;dice<=6;dice++){
            int j=i+dice;
            j+=board[j];
            if(j<=n){
                graph[i].pb(j);
            }
        }
    }
    cout<<bfs(1,n)<<'\n';
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    //double    pi=3.14159265358979323846;
    //sieve();
    int t=1;
    
    cin>>t;

    for(int tc=1;tc<=t;tc++){
       solve();

    }
    
    return 0;
    
}