#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define Pii pair<int,int>
#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;

struct dsu {
    vector<int> par;
    vector<int> rank;
    vector<int> sz;

    void init(int n){
        par.resize(n);
        rank.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
            sz[i]=1;
        }
    }

   int findpar(int node ){
        if(node == par[node])
            return node;
        return par[node] = findpar(par[node]);
    }

    void unite( int u , int v){
        int p1 = findpar(u );
        int p2 = findpar(v );
        if(p1!=p2)
        {
            int r1 = rank[p1];
            int r2 = rank[p2];
            if(r1 < r2)
            {
                par[p1] = p2;
                sz[p2]+=sz[p1];
                sz[p1]=0;
                rank[p2]++;
            }
            else
            {
               par[p2] = p1;
               sz[p1]+=sz[p2];
                sz[p2]=0;
               rank[p1]++;
            }
        }
    }

} G;
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    //double    pi=3.14159265358979323846;
    //sieve();
    int n,m;
    cin>>n>>m;
     G.init(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        G.unite(x,y);
    }
    vector<int> v;
    
    int ans=0;
    for(int i=0;i<n;i++){
        int p=G.findpar(i);
        ans+=(n-G.sz[p]);
    }
    cout<<(ans/2)<<'\n';
    
    return 0;
    
}