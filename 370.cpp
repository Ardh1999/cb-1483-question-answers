#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAX 1000005
#define mod (int)(1e9+7)
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

bool sub_tar(int subset[],int i,int target,vector<int> &dp,int n){
    if(target==0){
        return true;
    }
    if(i==n){
        return false;
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    bool include=false;
    if(target>=subset[i]){
        include=sub_tar(subset,i+1,target-subset[i],dp,n);
    }
    bool exclude=sub_tar(subset,i+1,target,dp,n);
    return dp[target]=(include or exclude);
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;

    int t=1;
    //cin>>t;
    while(t--){
        int n,target;
        cin>>n>>target;
        int subset[n];
        for(int i=0;i<n;i++){
            cin>>subset[i];
        }
        
        vector<int> dp(target+1,-1);
        if(sub_tar(subset,0,target,dp,n)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
        
    }

    return 0;
    
}