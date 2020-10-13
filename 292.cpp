#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define Pii pair<int,int>
#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;

vector<Pii> graph[3005];
int n,m;

void dijktra(int src){
    vector<int> dist(n+1);
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    set<Pii> st;
    dist[src]=0;
    st.insert({0,src});
    while(!st.empty()){
        auto p=*(st.begin());
        int node=p.second;
        int nodedist=p.first;
        st.erase(st.begin());
        for(auto x:graph[node]){
            if(nodedist+x.second < dist[x.first]){
                int dest=x.first;
                auto it=st.find({dist[dest],dest});
                if(it!=st.end()){
                    st.erase(it);
                }
                dist[dest]=x.second+nodedist;
                st.insert({dist[dest],dest});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=src){
            if(dist[i]==INT_MAX){
                cout<<"-1 ";
            }else{
                cout<<dist[i]<<' ';
            }
        }
    }
    cout<<endl;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        graph[i].clear();
    }
    for(int i=0;i<m;i++){
        int x,y,l;
        cin>>x>>y>>l;
        graph[x].pb({y,l});
        graph[y].pb({x,l});
    }
    int src;
    cin>>src;
    dijktra(src);
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