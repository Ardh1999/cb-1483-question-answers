#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAX 1000005
#define mod (int)(1e9+7)
#define sp fixed<<setprecision(12)


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //double    pi=3.14159265358979323846;

    int t=1;
    //cin>>t;
    //int it=1;
    while(t--){
        int n;
        cin>>n;  
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }  
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,dp[i]);
        }
        cout<<mx<<'\n';

    }

    return 0;
    
}
