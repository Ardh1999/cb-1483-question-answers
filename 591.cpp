#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define MAX 10000005
#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;
/*
vector<int> primes;
ll sumprime[MAX];
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
    for(int i=0;i<MAX;i++){
        if(!is_prime[i]){
            sumprime[i]=sumprime[i-1]+i;
        }else{
            sumprime[i]=sumprime[i-1];
        }
    }
}
*/


using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;
    //sieve();
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;
        vector<int> dp(m+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=a[i];j<=m;j++){
                dp[j]+=dp[j-a[i]];
				dp[j]%=mod;
            }
        }
        cout<<dp[m]<<'\n';
    }
    
    
    
    
    
    return 0;
    
}