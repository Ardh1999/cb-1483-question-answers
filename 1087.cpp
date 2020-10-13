#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define MAX 100005
#define mod (int)(1e18+7)
#define sp fixed<<setprecision(12)
using namespace std;

typedef pair<int,pair<int,int>> node;

vector<int> merge_k_sorted_array(vector<vector<int>> &v){
    vector<int> res;
    priority_queue<node,vector<node>,greater<node>> pq;
    for(int i=0;i<v.size();i++){
        pq.push({v[i][0],{i,0}});
    }
    while(!pq.empty()){
        node element=pq.top();
        pq.pop();
        int val=element.first;
        res.pb(val);
        int row=element.second.first;
        int col=element.second.second;

        if(col+1<v[row].size()){
            pq.push({v[row][col+1],{row,col+1}});
        }
    }
    return res;
}

void solve(){
    int n,k;
    cin>>k>>n;
    vector<vector<int>> v(k,vector<int>(n));
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<int> ans=merge_k_sorted_array(v);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;

    int t=1;
    //cin>>t;
    while(t--){
        solve();   
    }

    return 0;
    
}