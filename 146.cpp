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
        vector<int> dp(capa+1,0);
        for(int i=1;i<=capa;i++){
            for(int j=0;j<n;j++){
                if(weight[j]<=i){
                    dp[i]=max(dp[i],value[j]+dp[i-weight[j]]);
                }
            }
        }
        cout<<dp[capa]<<'\n';
    }

    return 0;
    
}