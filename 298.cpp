#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAX 1000005
#define mod (int)(1e9+7)
#define sp fixed<<setprecision(12)
   
int a[1001];
int dp[1001][1001];

int sum(int s,int e){
    int ans=0;
    for(int i=s;i<=e;i++){
        ans+=a[i];
        ans%=100;
    }
    return ans;
}

int mixtures(int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j]=min(dp[i][j],mixtures(i,k)+mixtures(k+1,j)+(sum(i,k)*sum(k+1,j)));
    }
    return dp[i][j];
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;

    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        cout<<mixtures(0,n-1)<<'\n';
        
    }

    return 0;
    
}