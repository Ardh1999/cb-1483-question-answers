#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAX 100005
#define mod (int)(1e18+7)
#define sp fixed<<setprecision(12)

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //double    pi=3.14159265358979323846;

    int t=1;
    cin>>t;
    //int it=1;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int dp[n];
        bool f=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
			dp[i]=MAX;
		}
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=min(i+a[i],n-1);j++){
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        cout<<dp[n-1]<<"\n";
        
    }

    return 0;
    
}
