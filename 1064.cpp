#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAX 1000005
#define mod (int)(1e8)
#define sp fixed<<setprecision(12)
/*
vector<int> primes;
bool is_prime[MAX];
void sieve(){
    is_prime[0]=is_prime[1]=true;
    for(int i=4;i<MAX;i+=2){
        is_prime[i]=true;
    }
    for(int i=3;i*i<MAX;i+=2){
        if(!is_prime[i]){
            for(int j=i*i;j<MAX;j+=i){
                is_prime[j]=true;
            }
        }
    }
    for(int i=1;i<MAX;i++){
        if(!is_prime[i]){
            primes.pb(i);
        }
    }
    
}
/*
int power(int a,int n,int p){
    int res=1;
    while(n){
        if(n&1){
            res=(res*a)%p;
            n--;
        }else{
            a=(a*a)%p;
            n/=2;
        }
    }
    return res;
}
*/

int knapsackpd(int weight[],int value[],int capa,int n){
    vector<vector<int>> dp(n+1,vector<int>(capa+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=capa;i++){
        dp[n][i]=0;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=capa;j++){
            int include=INT_MIN;
            if(weight[i]<=j){
                include=value[i]+dp[i+1][j-weight[i]];
            }
            int exclude=dp[i+1][j];
            dp[i][j]=max(include,exclude);
        }
    }
    
    return dp[0][capa];
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;

    int t=1;
    //cin>>t;
    while(t--){
        int n,capa;
        cin>>n>>capa;
        int value[n],weight[n];
        for(int i=0;i<n;i++){
            cin>>weight[i];
        }
        for(int i=0;i<n;i++){
            cin>>value[i];
        }
        cout<<knapsackpd(weight,value,capa,n)<<'\n';
    }

    return 0;
    
}
